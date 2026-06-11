#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<queue>
#define maxn 100005
using namespace std;
typedef long long ll;
struct nod
{
	ll dis,id;
	nod(ll x,ll y)
	{
		dis=x;
		id=y;
	}
	nod(){}
};
bool operator<(nod a,nod b)
{
	return a.dis>b.dis;
}
int n,m,tot;
int head[maxn],nex[maxn<<2],to[maxn<<2],deg[maxn];
ll val[maxn<<2];
void add(int x,int y,ll z)
{
	to[++tot]=y; val[tot]=z; nex[tot]=head[x]; head[x]=tot;
}
ll dis[maxn];
bool vis[maxn],flag=true;
priority_queue<nod> q;
void spfa(int now)
{
//	q.push(nod(0,start)); dis[start]=0;
//
//	while(!q.empty())
//	{
//		int now=q.top().id; q.pop();
//		if(vis[now]) continue;
//		vis[now]=1;
//
//		for(int i=head[now];i;i=nex[i])
//		{
//			if(dis[to[i]]==-1 || dis[to[i]]>dis[now]+val[i])
//			{
//				dis[to[i]]=dis[now]+val[i];
//				q.push(nod(dis[to[i]],to[i]));
//			}
//		}
//	}
	if(!flag) return;
	if(vis[now]) return;
	vis[now]=1;
	for(int i=head[now];i;i=nex[i])
	{
		if(!vis[to[i]])
		{
			if(dis[to[i]]==-1 || dis[to[i]]!=dis[now]+val[i])
			{
				dis[to[i]]=dis[now]+val[i];
//				vis[to[i]]=1;
				spfa(to[i]);
			}
		}
		else
		{
			if(dis[to[i]]!=dis[now]+val[i])
			{
				flag=false;
				return;
			}
		}
	}
	vis[now]=0;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int x,y; ll z;
		scanf("%d%d%lld",&x,&y,&z);
		add(x,y,z);
		add(y,x,-z);
	}

	memset(dis,-1,sizeof(dis));

	for(int i=1;i<=n;i++)
		if(dis[i]==-1)
		{
			spfa(i);
			if(!flag)
			return printf("No\n"),0;
		}

	for(int i=1;i<=n;i++)
	{
		for(int j=head[i];j;j=nex[j])
		{
			if(dis[to[j]]!=dis[i]+val[j])
			{
				return printf("No\n"),0;
			}
		}
	}

	printf("Yes\n");
}
