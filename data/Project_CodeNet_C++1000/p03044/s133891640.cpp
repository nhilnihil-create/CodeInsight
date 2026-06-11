#pragma GCC optimize ("O3")
#pragma GCC optimize("unroll-loops")
#include"bits/stdc++.h"
using namespace std;
#define v first
#define w second
vector<int> col;
vector<vector<pair<int,int>>>g;
int n;
void dfs(int node=0, int par=-1, int c=0)
{
	col[node]=c;
	for(auto u:g[node])
	{
		if(u.v==par)continue;
		if(u.w&1)dfs(u.v,node,c^1);
		else dfs(u.v,node,c);
	}
}
int32_t main()
{
	cin>>n;
	col=vector<int>(n);
	g=vector<vector<pair<int,int>>>(n);
	int x,y,u;
	for(int i=1;i<n;i++)
	{
		cin>>x>>y>>u;
		x--;y--;
		g[x].push_back({y,u});
		g[y].push_back({x,u});
	}
	dfs();
	
	for(int i=0;i<n;i++)
	{
		cout<<col[i]<<'\n';
	}
	
}