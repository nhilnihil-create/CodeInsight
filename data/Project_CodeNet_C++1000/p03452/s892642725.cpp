#include <stdio.h>
int dis[100009];
int pre[100009];
int find(int num)
{
	if(pre[num]==num)
	{
		
		return num;
	}
	
	int root=find(pre[num]);
	
	dis[num]+=dis[pre[num]];
	
	return pre[num]=root;
}
int check(int left,int right,int diss)
{
	int fl=find(left), fr=find(right);
//	printf("%d %d  %d %d<<\n",left,fl,right,fr);
	if(fl==fr)
	{
	//	printf("%d %d<<\n",dis[left],dis[right]);
		if((dis[right]-dis[left])==diss)
		{
			
			return 1;
		}else {
			return 0;
		}
	}
	
	pre[fr] = fl;
	
	dis[fr]=diss+dis[left]-dis[right];
//	printf("%d %d",fr,pre[fr]);
	return 1;
}

int main()
{
	int l,r,d;
	int num_case;
	int num_people;
	int flag;
	while(scanf("%d %d",&num_people,&num_case)!=EOF)
	{
		for(int i=1;i<=num_people;i++)
		{
			dis[i]=0;
			pre[i]=i;
		}
		flag=1;
		while(num_case--)
		{
			scanf("%d %d %d",&l,&r,&d);
			if( check(l,r,d) == 1 )
			{
				;
			}else {
				flag=0;
			}
		}
		if(flag)
		{
			printf("Yes\n");
		}else {
			printf("No\n");
		}
	}
}

