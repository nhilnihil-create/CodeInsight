#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using graph = vector<vector<ll>>;
ll n, m;
ll color[100000];
graph G;

bool dfs(ll v, ll c){
    color[v] = c;
    for(int i=0; i<G[v].size(); ++i){
        int nv = G[v][i];
        if(color[nv]!=-1){
            if(color[nv]==c){return false;}
        }
        else if(!dfs(nv, 1-c)){return false;}
    }
    return true;
}

int main(){
    cin >> n >> m;
    G.resize(n);
    memset(color, -1, sizeof(color));
    for(ll i=0; i<m; ++i){
        ll a, b; cin >> a >> b; a--; b--;
        G[a].push_back(b); G[b].push_back(a);
    }
    ll b = 0, w = 0;
    if(dfs(0, 1)){
        for(ll i=0; i<n; ++i){
            if(color[i]==1){b++;}
            else if(color[i]==0){w++;}
        }
        cout << b*w - m << endl;
    }else{
        cout << n*(n-1)/2 - m << endl;
    }
    return 0;
}