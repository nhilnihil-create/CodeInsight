#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<ctime>

//T1: Give you a tree.
//You can delete all of the leaves or save one leave when it's your turn.
//The person who can't do anything will lose the game.

const int N=200005;

int n,head[N];

struct Edge
{
	int next,to;
};
Edge E[N<<1];
int tot;
void add(int u,int v)
{
	E[++tot].next=head[u];
	E[tot].to=v;
	head[u]=tot;
}

namespace subtask3
{

int main()
{
	if(n%3==2)puts("Second");
	else puts("First");
	return 0;
}

}//namespace subtask3

int dis[N];
void dfs(int u,int fa)
{
	for(int i=head[u];i;i=E[i].next)
	{
		int v=E[i].to;
		if(v==fa)continue;
		dis[v]=dis[u]+1;
		dfs(v,u);
	}
}

int rho()
{
	dis[1]=0;
	dfs(1,0);
	int res=0;
	for(int i=1;i<=n;++i)
	{
		if(dis[i]>dis[res])res=i;
	}
	dis[res]=0;
	dfs(res,0);
	for(int i=1;i<=n;++i)
	{
		if(dis[i]>dis[res])res=i;
	}
	return dis[res]+1;
}

int main()
{
	int T=1;
	while(T--)
	{
		bool s3_flag=1;
		tot=0;
		memset(head,0x00,sizeof(head));
		scanf("%d",&n);
		for(int i=1;i<n;++i)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			add(u,v);
			add(v,u);
			if(u!=i||v!=i+1)s3_flag=0;
		}
		if(s3_flag)
		{
			subtask3::main();
			continue;
		}
		n=rho();
		subtask3::main();
	}
}
