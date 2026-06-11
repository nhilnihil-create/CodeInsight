//g++  7.4.0

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAXN 100005
#define MOD 1000000007
ll dp[MAXN][2];
vector<ll> adj[MAXN];

void DFS(ll s,ll p)
{
    dp[s][0] = 1;
    dp[s][1] = 1;
    
    for(auto it: adj[s])
    {
        ll v = it;
        if(v != p)
        {
            DFS(v,s);
            
            dp[s][0] = (dp[s][0] * dp[v][1])%MOD;
            dp[s][1] = (dp[s][1] * (dp[v][1] + dp[v][0])) % MOD;
            
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll N; cin>>N;
    for(ll i=0;i<(N - 1);++i)
    {
        ll u,v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    DFS(1,-1);
    
    cout<<(dp[1][0] + dp[1][1])%MOD<<endl;
}