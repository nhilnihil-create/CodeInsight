#pragma GCC optimize ("O3")
#pragma GCC optimize("unroll-loops")
#include"bits/stdc++.h"
using namespace std;
vector<bool> vis;
vector<vector<int>>g;
int n,m,u,v;
void dfs(int node)
{
	vis[node]=1;
	for(auto i:g[node])
	{
		if(!vis[i])
		{
			dfs(i);
		}
	}
}
int32_t main()
{
	
	cin>>n>>m;
	vis=vector<bool>(n);
	g=vector<vector<int>>(n);
	int z;
	for(int i=0;i<m;i++)
	{
		cin>>u>>v>>z;
		u--;v--;
		g[u].push_back(v);
		g[v].push_back(u);
		
	}
	int ans=0;
	for(int i=0;i<n;i++)
	{
		if(!vis[i]){ans++;dfs(i);}
	}
	
	cout<<ans;
	
	
	
}