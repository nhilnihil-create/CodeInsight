#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=1e5+5;
int n,m,fa[MAXN];
struct edge{
	int u,v;
}e[MAXN];
ll ans[MAXN],sz[MAXN];
int get_fa(int x) 
{
	if(x==fa[x]) 
		return x;
	return fa[x]=get_fa(fa[x]);
}
int main() 
{
	cin>>n>>m;
	for(int i=1;i<=m;i++) 
	{
		cin>>e[i].u>>e[i].v;
	}
	for(int i=1;i<=n;i++) 
	{
		fa[i]=i;
		sz[i]=1;
	}
	ans[m]=(ll)n*(n-1)/2;
	for(int i=m;i>=1;i--) 
	{
		int u=get_fa(e[i].u),v=get_fa(e[i].v);
		if(u==v) 	
		    ans[i-1]=ans[i];
		else 
		{
			ans[i-1]=ans[i]-sz[v]*sz[u];
			sz[v]+=sz[u]; 
			fa[u]=v;
		}
	}
	for(int i=1;i<=m;i++) 
	   cout<<ans[i]<<endl;
	return 0;
}