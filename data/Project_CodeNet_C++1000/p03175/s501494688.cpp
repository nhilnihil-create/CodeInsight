#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int mod=1e9 + 7;

ll ans=2;

void dfs(int p,int x,vector<vector<int>>& adj,vector<vector<ll>>& dp)
{
		dp[x][0]=dp[x][1]=1;
	
		for(int i=0;i<adj[x].size();i++)
		{
			if(adj[x][i]==p)
				continue;
			dfs(x,adj[x][i],adj,dp);
			dp[x][1]=(dp[x][1]*dp[adj[x][i]][0])%mod;
			dp[x][0]=(dp[x][0]*(dp[adj[x][i]][0]+dp[adj[x][i]][1])%mod)%mod;
			// ans=max(ans,(dp[x][1]+dp[x][0])%mod);
		}
}


int main()
{
	
	int n;
	cin>>n;
	int x,y;
	vector<vector<int>>adj(n+1);
	vector<vector<ll>>dp;    // 0 white 1 black
	

	for(int i=0;i<=n+1;i++)
		dp.push_back({0,0});

	for(int i=0;i<n-1;i++)
	{
		cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	dfs(1,1,adj,dp);
	cout<<(dp[1][0]+dp[1][1])%mod;
}
	


