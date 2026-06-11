#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
vector<ll>color;
void dfs(vector<vector<pair<ll,ll>>> &G,ll v,ll cur=0){
    color[v]=cur;
    for(auto x: G[v]){
        ll a=x.first;
        ll w=x.second;
        if(color[a]!=-1) continue;
        ll c=(cur+w)%2;
        dfs(G,a,c);
    }
}
int main() {
    ll n;
    cin >> n;
    ll odd=0;
    vector<vector<pair<ll,ll>>>graph(n);
    for(ll i=0;i<n-1;i++){
        ll u,v,w;
        cin >> u >> v >> w;
        u--;v--;
        graph[u].push_back({v,w});
        graph[v].push_back({u,w});
    }
    color.assign(n,-1);
    dfs(graph,0);
    for(ll i=0;i<n;i++){
        cout << color[i] << endl;
    }
}
