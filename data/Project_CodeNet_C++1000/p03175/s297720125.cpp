#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod (ll)(1e9+7)
ll vec[(ll)1e5+1][2];

ll dfs(ll s,ll e,vector<ll>*adj,ll flag){
    if(vec[s][flag]!=-1) return vec[s][flag];
    vec[s][flag] = 1;
    for(auto u : adj[s]){
        if(u==e) continue;
        if(flag) vec[s][flag] = vec[s][flag] * dfs(u,s,adj,0) % mod;
        else vec[s][flag] = vec[s][flag] * (dfs(u,s,adj,0)%mod + dfs(u,s,adj,1)%mod) % mod;
    }
    return vec[s][flag];
}

int main(){
    memset(vec,-1,sizeof vec);
    ll n;
    cin >> n;
    vector<ll>adj[n];
    ll x,y;
    for(ll i = 0;i < n-1;i++){
        cin >> x >> y;
        x--,y--;
        adj[x].emplace_back(y),adj[y].emplace_back(x);
    }
    vec[0][0] = dfs(0,-1,adj,0);
    vec[0][1] = dfs(0,-1,adj,1);
    cout<<(vec[0][0] + vec[0][1])%mod;
}