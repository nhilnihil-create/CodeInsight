#include<bits/stdc++.h>
using namespace std;
const int N=1000005;
int n,top,x,y,ans,ma,dis[N],head[N];
struct node{
	int too,next;
}edge[N*2];
void add(int a,int b)
{
	edge[++top].too=b;edge[top].next=head[a];head[a]=top;
}
void dfs(int u,int fa)
{
	dis[u]=dis[fa]+1;
	if(dis[u]>ma)
	{
		ma=dis[u];
		ans=u;
	}
	for(int i=head[u];i;i=edge[i].next)
	{
		int v=edge[i].too;
		if(v==fa)continue;
		dfs(v,u);
	}
}
int main()
{
	int T;
	T=1;
	while(T--)
	{
		scanf("%d",&n);
		top=0;
		memset(head,0,sizeof(head));
		for(int i=1;i<n;i++)
		{
			scanf("%d%d",&x,&y);
			add(x,y);
			add(y,x);
		}
		memset(dis,0,sizeof(dis));
		ma=0,ans=0;
		dfs(1,0);
		memset(dis,0,sizeof(dis));
		x=ans;
		ma=0,ans=0;
		dfs(x,0);
		if(ma==1)
		{
			puts("First");
			continue;
		}
		if((ma-2)%3==0)puts("Second");
		else puts("First");
	}
}
/*
如果选的是叶子，最后一层就只有这一个点了
如果不是叶子，叶子全消除
说明要么去掉一层，要么去掉两层
直径一定是两个叶子 
*/
/*
3
3
1 2
2 3
6
1 2
2 3
2 4
4 6
5 6
7
1 7
7 4
3 4
7 5
6 3
2 1
*/