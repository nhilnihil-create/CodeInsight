#include <bits/stdc++.h>
#define rep(i, n)  for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, ll>;

// color -1: 未訪問, 0:白, 1:黒
void dfs(vector<vector<P>> &G, vector<int> &C, int v, int color){
    C[v] = color;
    for(auto pair : G[v]){
        if(C[pair.first] != -1) continue; // 訪問済
        dfs(G, C, pair.first, (pair.second % 2 == 0) ? color : (1 - color));
    }
}

int main(){
    int N; cin >> N;
    vector<vector<P>> graph(N);
    rep(i, N-1){
        int u, v, w;
        cin >> u >> v >> w;
        graph[u-1].push_back(P(v-1, w));
        graph[v-1].push_back(P(u-1, w));
    }

    vector<int> colors;
    colors.assign(N, -1);
    rep(i, N){
        if(colors[i] != -1) continue;
        dfs(graph, colors, i, 0);
    }
    rep(i, N) cout << colors[i] << endl;
}