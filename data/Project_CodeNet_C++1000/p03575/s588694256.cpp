#include<bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define ll long long
#define all(x) (x).begin(),(x).end()
#define rep(i, n) for(ll i = 0; i < n; i++)
const ll INF = 1LL << 60;


vector<bool> seen;
void dfs(Graph &G, int v){
    seen[v] = true;
    for(auto x:G[v]){
        if(seen[x])continue;
        dfs(G, x);
    }
}

int main(){
    int N, M; cin >> N >> M;
    vector<pair<int, int>> edges(M);
    rep(i, M){
        int a, b; cin >> a >> b;
        a--;b--;
        edges[i] = {a, b};
    }
    
    int ans = 0;
    rep(i, M){
        Graph G(N, vector<int>());
        rep(j, M){
            if(i != j){
                G[edges[j].first].push_back(edges[j].second);
                G[edges[j].second].push_back(edges[j].first);
            }
        }
        seen.assign(N, false);
        dfs(G, 0);
        bool res = all_of(all(seen), [](bool x) {return x == true; });
        if(!res) ans++;
    }
    cout << ans << endl;
}