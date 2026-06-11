#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const int N=1e5+5;
const int mod=1e9+7;
bool vis[N]={false};
vector<int> adj[N];
ll dp[N][2];
void dfs(int s)
{
	vis[s]=true;
	dp[s][0]=1;
	dp[s][1]=1;
	int x;
	for(int i=0;i<adj[s].size();i++)
	{
		x=adj[s][i];
		if(vis[x]==0)
		{
			dfs(x);
			dp[s][1]=((dp[s][1]*((dp[x][0]+dp[x][1])%mod))%mod);
			dp[s][0]=(dp[s][0]*dp[x][1])%mod;
		}
	}
	
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	int  x,y;
	for(int i=0;i<n-1;i++)
	{
		cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	dfs(1);
	cout<<(dp[1][0]+dp[1][1])%mod;
	return 0;
}