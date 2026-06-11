#include<bits/stdc++.h>
int n,m,i,head[100005],Next[200005],adj[200005],u,v,c[100005],ansa,ansb,k;
void Push(int u,int v)
{
	Next[++k]=head[u];
	head[u]=k;
	adj[k]=v;
}
void dfs(int i,int d)
{
	int j;
	c[i]=d;
	for(j=head[i];j!=0;j=Next[j])
		if(c[adj[j]]==-1)
			dfs(adj[j],d^1);
		else
			if(c[adj[j]]!=(d^1))
			{
				printf("%lld",1ll*n*(n-1)/2-m);
				exit(0);
			}
}
int main()
{
	scanf("%d %d",&n,&m);
	for(i=1;i<=m;++i)
	{
		scanf("%d %d",&u,&v);
		Push(u,v);
		Push(v,u);
	}
	memset(c,-1,sizeof(c));
	dfs(1,0);
	for(i=1;i<=n;++i)
		if(c[i])
			++ansa;
		else
			++ansb;
	std::cout<<1ll*ansa*ansb-m;
}
