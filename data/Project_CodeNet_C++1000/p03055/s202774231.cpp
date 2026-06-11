#include <bits/stdc++.h>
#define pb push_back
using namespace std;

pair<int, int> point={0,0};
vector<int> adj[200005];

void dfs(int node, int fa, int dist)
{
	point=max(point, {dist, node});
	for(auto i:adj[node])
	{
		if(i==fa) continue;
		dfs(i, node, dist+1);
	}
}

signed main()
{
	int n;
	cin>>n;
	for(int i=1; i<n; i++)
	{
		int u, v;
		cin>>u>>v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	dfs(1, 1, 1);
	dfs(point.second,point.second,1);
	if(point.first%3==2)
	{
		cout<<"Second";
	}
	else
	{
		cout<<"First";
	}
}