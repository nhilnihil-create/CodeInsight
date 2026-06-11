#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod= int(1e9)+7;
using P = pair<ll,ll>;
using ld=long double;
const int N_MAX=1e5;
vector<vector<P>>g(N_MAX);
vector<ll>color(N_MAX,0);

void dfs(ll u,ll p=-1){
    for(auto v:g[u]){
        if(v.first==p)continue;
        if(v.second%2)color[v.first]=1-color[u];
        else color[v.first]=color[u];
        dfs(v.first,u);
    }
}
int main(){
    ll n;cin >>n;
    for (int i = 0; i < n - 1; ++i) {
        ll u,v,w;cin >>u>>v>>w;u--;v--;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    dfs(0);
    for (int i = 0; i < n; ++i) {
        cout <<color[i]<<endl;
    }
    return 0;
}