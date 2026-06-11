#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=100005;
int n,p[N],sz[N],U[N],V[N];ll tot,d[N];
map<ll,int>mp;vector<int>G[N];
inline bool cmp(int x,int y){return d[x]>d[y];}
void dfs(int x,int d){tot+=d;for(int i=0;i<G[x].size();i++)dfs(G[x][i],d+1);}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%lld",&d[i]),mp[d[i]]=i,sz[i]=1,p[i]=i;
	sort(p+1,p+n+1,cmp);
	for(int i=1;i<n;i++)
	{
		int x=p[i];ll w=d[x]-(n-sz[x])+sz[x];
		if(!mp[w]||w>=d[x]){puts("-1");return 0;}
		int y=mp[w];U[i]=x;V[i]=y;
		sz[y]+=sz[x];G[y].push_back(x);
	}
	dfs(p[n],0);
	if(tot!=d[p[n]]){puts("-1");return 0;}
	for(int i=1;i<n;i++)printf("%d %d\n",U[i],V[i]);
	return 0;
}
