#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mk make_pair
#define all(v) v.begin(),v.end()
#define fi first
#define se second
#define vl vector<long long int>
#define vvl vector<vector<ll> > 
#define fo(i,a,b) for(int i=a;i<b;i++)
#define rof(i,a,b)  for(int i=b;i>=a;i--)
using namespace std;
ll mod=1000000007;
ll dfs(ll node,ll vis[],ll dp[],vector<ll> adj[])
{
    if(vis[node])
        return dp[node]+1;
    vis[node]=1;ll maxi=0;
    for(ll i=0;i<adj[node].size();i++)
    {
        maxi = max(maxi,dfs(adj[node][i],vis,dp,adj));
    }
    dp[node] = maxi;
    return maxi+1;
}
int main()
{
    ll n,m;cin>>n>>m;
    vector<ll> adj[n];
    fo(i,0,m)
    {
        ll x,y;cin>>x>>y;
        adj[x-1].pb(y-1);
    }
    ll dp[n+1],vis[n+1];
    memset(dp,-1,sizeof(dp));
    memset(vis,0,sizeof(vis));
    fo(i,0,n)
        if(!vis[i])
            dfs(i,vis,dp,adj);
    ll res=0;
    fo(i,0,n)
        res = max(res,dp[i]);
    cout << res;
}

