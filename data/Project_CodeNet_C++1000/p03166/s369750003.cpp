#include <bits/stdc++.h>
using namespace std;
int vis[100001], dp[100001];
vector<int>ar[100001];
int c;
void dfs(int node)
{
	vis[node]=1;
	dp[node]=0;
	for(int i:ar[node])
	{
		if(vis[i]==0)
		dfs(i);
		dp[node]=max(dp[node],1+dp[i]);
	}
}
int main() 
{
	int n,m,x,y;
	cin>>n>>m;
	while(m--)
	{
		cin>>x>>y;
		ar[x].push_back(y);
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i]==0)
		dfs(i);
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	ans=max(dp[i],ans);
	cout<<ans;
	
	return 0;
}