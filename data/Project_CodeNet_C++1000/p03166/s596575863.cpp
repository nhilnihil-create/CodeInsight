#include<iostream>
using namespace std;
struct Edge{
	int v,next;
}edge[100001];
int head[100001],tot=0;
void addedge(int u,int v)
{
	tot++;
	edge[tot].v=v;
	edge[tot].next=head[u];
	head[u]=tot;
}
int mx[100001];
void dfs(int u)
{
	if(mx[u])return;
	mx[u]=1;
	for(int i=head[u];i;i=edge[i].next)
	{
		int v=edge[i].v;
		dfs(v);
		mx[u]=max(mx[u],mx[v]+1);
	}
}
int main()
{
	int n,m;cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int u,v;cin>>u>>v;
		addedge(u,v);
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(!mx[i])dfs(i);
		ans=max(ans,mx[i]);
	}
	cout<<ans-1;
	return 0;
}