#include<bits/stdc++.h>
#define pb push_back
#define INF 10000009
using namespace std;

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int longestPath(vector<int> graph[],vector<int> &dp,int s)
{
	if(dp[s]!=0)
	{
		return dp[s];
	}
	int ch=0;
	for(auto v:graph[s])
	{
		ch=max(ch,1+longestPath(graph,dp,v));
	}
	return dp[s]=ch;
}

int main()
{
	fastio
	int n,m,i,u,v;
	cin>>n>>m;
	vector<int> graph[n+1];
	vector<int> dp(n+1,0);
	for(i=0;i<m;i++)
	{
		cin>>u>>v;
		graph[u].pb(v);
	}
	int ans=0;
	for(i=1;i<=n;i++)
	{
		if(dp[i]==0)
		{
			ans=max(ans,longestPath(graph,dp,i));
			if(ans==n)
			{
				break;
			}
		}
	}
	cout<<ans;
}