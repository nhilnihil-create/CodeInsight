#pragma GCC optimize ("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse4")
#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
#define int ll
#define sz(x) (int)(x).size();
#define all(x) x.begin(), x.end()
#define trav(i,a) for(auto &i:a) 
inline int in(){int x;scanf("%lld",&x);return x;}
vector<vector<int>> g;
vector<bool> vis;
void dfs(int node)
{
	vis[node]=1;
	for(auto u:g[node])
	{
		if(!vis[u])dfs(u);
	}
}
int32_t main()
{
	int n=in();int m=in();int u,v;
	vector<pair<int,int>>edg;
	for(int i=0;i<m;i++)
	{u=in();v=in();u--;v--;edg.push_back({u,v});}
	int cmp=0;
	int ans=0;
	for(int leave=0;leave<m;leave++)
	{
		cmp=0;
		g=vector<vector<int>>(n);
		vis=vector<bool>(n);
		for(int i=0;i<m;i++)
		{
			if(i==leave)continue;
			g[edg[i].first].push_back(edg[i].second);
			g[edg[i].second].push_back(edg[i].first);
		}
		
		for(int i=0;i<n;i++)
		{
			if(!vis[i]){cmp++;dfs(i);}
		}
		if(cmp>1)ans++;
	}
	cout<<ans;
	
	
	
}