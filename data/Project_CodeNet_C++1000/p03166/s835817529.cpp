#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> dp;
vector<bool> vis;

void solve(int u)
{
	vis[u]=true;
	
	for(auto x:adj[u])
	{
		if(!vis[x])
		  solve(x);
	  dp[u]=max(dp[u],1+dp[x]);	  
	}
}
int main()
{
	int n,m;
	cin>>n>>m;
	adj.resize(n+1);
	dp.resize(n+1,0);
	vis.resize(n+1,false);
	
	for(int i=0;i<m;i++)
	{
		int a,b;
		cin>>a>>b;
		adj[a].push_back(b);
	}
	
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		  solve(i);
	}
	cout<<*max_element(dp.begin(),dp.end())<<endl;
}