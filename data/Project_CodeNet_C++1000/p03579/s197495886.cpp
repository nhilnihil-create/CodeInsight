#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define rep(i,n) for(ll i=0;i<(ll)n;i++)

using Graph = vector<vector<int> >;

vector<int> color;

bool dfs(Graph &G, int v, int cur = 0){
    color[v] = cur;
    for(auto nv : G[v]){
        if(color[nv]!=-1){
            if(color[nv] == cur) return false;
            continue;
        }

        if(!(dfs(G,nv,1-cur) ) )  return false;
    }
    return true;
}

int main(){
    ll N,M; cin >> N >> M;
    Graph G(N+1);
    rep(i,M){
        int a,b; cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    color.assign(N+1,-1);
    bool is_bipartite = true;
    rep(v,N){
        if(color[v]!=-1) continue;
        if(!(dfs(G,v)) ) is_bipartite = false;
    }

    ll res = 0;
    if(is_bipartite){
        ll B=0,W=0;
        rep(v,N){
            if(color[v]) W++;
            else B++;
        }
        res = B*W-M;
    }else{
        res = N*(N-1)/2 - M;
    }

    cout << res << endl;
}