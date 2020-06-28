#include <stdio.h>
#include<stdlib.h>
struct node 
{
    int data;
    struct node *next;
}*head;

//creating a circular linked list
void create(int A[],int n)
{
    struct node *t,*last;
    head=(struct node *)malloc(sizeof(struct node));
    head->data=A[0];
    head->next=head;
    last=head;
    
    for(int i=1;i<n;i++)
    {
        t=(struct node *)malloc(sizeof(struct node));
        t->data=A[i];
        t->next=last->next;
        last->next=t;
        last=t;
    }
}

//displaying..
void display1(struct node *h)
{
    printf("%d ",head->data);
    h=h->next;
    while(h!=head)
    {
    printf("%d ",h->data);
      h=h->next;
  }
}
void display(struct node *h)
{
  do
  {
      printf("%d ",h->data);
      h=h->next;
  }while(h!=head);
}

//recursively displaying

void rdisplay(struct node *h)
{
    static int flag=0;
    if(h!=head || flag==0)
    {
        flag=1;
        printf("%d ",h->data);
        rdisplay(h->next);
    }
    flag=0;
}
//length of the list
int length(struct node *p)
{
    int len =0;
    do{
        len++;
        p=p->next;
    }while(p!=head);
    return len;
}
//inserting ...
void insert(struct node *p,int index,int x)
{
    struct node *t;
    if(index> 0  || index <length(head))
    {
        if(index==0)
        {
            t=(struct node *)malloc(sizeof(struct node));
            t->data=x;
            if(head==NULL)
            {
                head=t;
                head->next=head;
            }else
            {
                while(p->next !=head)
                {
                    p=p->next;
                }
                t=(struct node *)malloc(sizeof(struct node));
                t->data=x;
                p->next=t;
                t->next=head;
                head=t;
                
            }
        }
        else
        {
            for(int i=0;i<index-1;i++)
            {
                p=p->next;
            }
            t=(struct node *)malloc(sizeof(struct node));
            t->data=x;
            t->next=p->next;
            p->next=t;
        }
    }
}

//deleting 
int delete(struct node *p,int index)
{
    struct node *q;int x;
    if(index>0 || index<length(head))
    {
        if(index==1)
        {
            while(p->next !=head)
            {
                p=p->next;
            }
            p->next=head->next;
            x=head->data;
            free(head);
            head=p->next;
            if(head==p)
            {
                x=head->data;
                free(head);
            }
        }
        else
        {
          for(int i=1;i<index-1;i++) 
          {
              p=p->next;
          }
          q=p->next;
          p->next=q->next;
          x=q->data;
          free(q);
        }
    }return x;
}
int main()
{
    int A[]={2,3,4,8,9};
    create(A,5);
    printf("length of the list id %d\n",length(head));
    display(head);
    printf("\n");
    insert(head,3,10);
    display(head);
    printf("\n");
    printf("deleted element is %d\n",delete(head,2));
    display(head);

    return 0;
}
