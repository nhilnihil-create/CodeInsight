#include <iostream>
#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
using namespace std;
using ll = long long int;
const int p = 1e9 + 7;
void solve(){
    int n;
    cin>>n;
    vector<vector<int>> adj(n);
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        --u;--v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    vector<ll> dpblack(n, 1);
    vector<ll> dpwhite(n, 1);
    function<void(int,int)> dfs = [&](int u, int par){
        ll &w = dpwhite[u];
        ll &b = dpblack[u];
        for(const auto &e : adj[u]){
            if(e==par){
                continue;
            }
            dfs(e, u);
            w*=(dpblack[e] + dpwhite[e]);
            b*=dpwhite[e];
            w%=p;
            b%=p;
        }
    };
    dfs(0,-1);
    cout<<(dpblack[0] + dpwhite[0])%p;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}