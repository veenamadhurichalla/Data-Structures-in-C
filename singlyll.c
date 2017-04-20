/******* Singly Linked List *******/
/* insert_beg */
/* search */
/* replace the element  at given position */
/* insert a node after given postion */
/* delete a node at given postion */
/* swapping given node with adjacent node */
/* reversing the linked list */

#include<stdio.h>
#include<stdlib.h>

struct node{
		int data;
		struct node *next;
	   };
struct node *head;

struct node *add_beg(struct node *,int );
//void search(struct node *);
//void replace_pos(int , int);
void disp();
void insert_after_pos(int ,int);
void delete(int );
void swap_adj(int);
struct node *rev_list(struct node *);

int main()
{
	//struct node *head;
	int num,count,element,elem,pos,dpos,spos;
	head=NULL;
	printf("Enter number of nodes to be inserted:\t");
	scanf("%d",&num);
	for(count=1;count<=num;count++)
	{
		printf("enter the element in %d node:\t",count);
		scanf("%d",&element);
		head=add_beg(head,element);
	}
	//display(head);
	disp();
	head=rev_list(head);
	printf("After reversing the linked list\n");
	disp();
	//search(head);
/*	printf("Enter the element to be inserted:\t");
	scanf("%d",&elem);
	printf("Enter the position of the element:\t");
	scanf("%d",&pos);
	//replace_pos(pos,elem);
	insert_after_pos(pos,elem);
	disp();*/
	printf("Enter the position of node to be deleted:\t");
	scanf("%d",&dpos);
	delete(dpos);
	disp();
/*	printf("**** SWAPPING ADJACENT ELEMENTS ****\n Enter the postion of node to be swapped:\t");
	scanf("%d",&spos);
	swap_adj(spos);
	disp();*/
	return 0;
}

struct node *add_beg(struct node *head,int element)
{
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->data=element;
	temp->next=NULL;
	if(head==NULL)
	{
		head=temp;
		return head;
	}
	temp->next=head;
	head=temp;
	return head;
}

/*void display(struct node *head)
{
	if(head==NULL)
	return;
	printf("%d\t",head->data);
	display(head->next);

} */ 

struct node *rev_list(struct node *head)
{
	struct node *prev,*current,*nnext;
	prev=NULL;
	current=head;
	nnext=current->next;
	if(current==NULL)
	{
		return head;;
	}
	while(nnext!=NULL)
	{
		current->next=prev;
		prev=current;
		current=nnext;
		nnext=nnext->next;
	}
	current->next=prev;
	head=current;
	return head;
}

void search(struct node *head)
{
	int key,cnt=1,pos;
	printf("Enter element to search:\t");
	scanf("%d",&key);
	while(head!=NULL)
	{
		if(head->data==key)
		{
			printf("element found at %d position\n",cnt);
			return;
		}
		head=head->next;
		cnt++;
	}
	printf("key not found\n");
}

void replace_pos(int pos,int elem)
{
	struct node *temp;
	int cnt=1;
	temp=head;
	while(temp->next!=NULL)
	{
		if(cnt==pos)
		{
			temp->data=elem;
			return;
		}
		temp=temp->next;
		cnt++;
	}
	return ;
}

void insert_after_pos(int pos,int elem)
{
	struct node *temp,*prev,*nnext;
	int cnt=1;
	temp=(struct node *)malloc(sizeof(struct node));
	prev=head;
	temp->data=elem;
	temp->next=NULL;
	while(prev->next!=NULL)
	{
		if(cnt==pos)
		{
			nnext=prev->next;
			prev->next=temp;
			temp->next=nnext;
			return;
		}
		prev=prev->next;
		cnt++;
	}
	if(prev->next==NULL)
	{
		prev->next=temp;
		return;
	}
	return;
}

void delete(int dpos)
{
	struct node *temp,*prev,*nnext;
	int cnt=1;
	temp=head;
	prev=temp;
	while(temp->next!=NULL)
	{
		if(dpos==cnt)
		{
			nnext=temp->next;
			prev->next=nnext;
			free(temp);
			return;	
		}
		prev=temp;
		temp=temp->next;
		cnt++;
	}
	if(temp->next==NULL)
	{
		prev->next==NULL;
		free(temp);
		return;
	}
	return;
}

void swap_adj(int spos)
{
	int cnt=1,val;
	struct node *temp,*prev,*nnext;
	temp=head;
	while(temp->next!=NULL)
	{
		if(cnt==spos)
		{
			nnext=temp->next;
			val=temp->data;
			temp->data=nnext->data;
			nnext->data=val;
			return;
		}
		cnt++;
		prev=temp;
		temp=temp->next;
	}
	printf("entered a valid position of node\n");
	return;
}

void disp()
{
	struct node *temp;
	temp=head;	
	printf("\nElements in the linked list are \t");
	while(temp->next!=NULL)
	{
		printf("%d\t",temp->data);
		temp=temp->next;
	}
	printf("%d\n",temp->data);
}
