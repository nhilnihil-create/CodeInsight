#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define F first
#define S second


void dfs(vector<int> graph[],vector<ll> &dp,vector<int> &vis,int u)
{
  vis[u]=1;
  for(int i=0;i<graph[u].size();i++)
  {
    if(vis[graph[u][i]]==0)
      dfs(graph,dp,vis,graph[u][i]);

    dp[u]=max(dp[u],1+dp[graph[u][i]]);
  }
}
int main()
{
  ll n,m;
  cin>>n>>m;
  vector<int> graph[n];
  for(int i=0;i<m;i++)
  {
    ll x,y;
    cin>>x>>y;
    graph[x-1].push_back(y-1);
  }
  vector<int> vis(n,0);
  vector<ll> dp(n,0);
  for(int i=0;i<n;i++)
  {
    if(vis[i]==0)
      dfs(graph,dp,vis,i);
  }

  ll maxi=0;
  for(int i=0;i<n;i++)
    maxi=max(maxi,dp[i]);

  cout<<maxi<<endl;
}
