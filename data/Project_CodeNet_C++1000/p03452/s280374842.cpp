#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;
using Graph = vector<vector<pair<int, int>>>;

const ll INF = 1001001001;
vector<int> dist;
bool ok;

void dfs(int v, int cost, const Graph &G){
    dist[v] = cost;
    for(auto p : G[v]){
        int nv = p.first, dis = p.second;
        if(dist[nv] != -INF){
            if(dist[v] + dis == dist[nv]) continue;
            ok = false;
            return;
        }
        else{
            dfs(nv, cost + dis, G);
        }
    }
}

int main(){
    int n, m; cin >> n >> m;
    Graph G(n);
    dist.resize(n, -INF);
    for(int i = 0; i < m; i++){
        int l, r, d; cin >> l >> r >> d;
        --l; --r;
        G[l].push_back({r, d});
        G[r].push_back({l, -d});
    }
    ok = true;
    for(int i = 0; i < n; i++){
        if(dist[i] == -INF){
            dfs(i, 0, G);
        }
        if(!ok) break;
    }
    if(ok) cout << "Yes" << endl;
    else cout << "No" << endl;
}
