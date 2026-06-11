#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<pair<int, int>>>;
vector<int> color;
/////black: 1, white: 0, undecided: -1

void dfs(const Graph &G, int u, int this_color){
    color[u] = this_color;
    for (auto next: G[u]){
        int w = next.second;
        int next_u = next.first;
        if (color[next_u] != -1) continue;
        int next_color = this_color;
        if (w % 2 == 1) {next_color = 1 - this_color;}
        dfs(G, next_u, next_color);
        // if (w % 2 == 1) dfs(G, next_u, 1 - this_color);
        // else dfs(G, next_u, this_color);
        // color[next_u] = this_color;
        // dfs(G, next_u, u, this_color);
    }
}

int main() {
    int N;
    cin >> N;
    Graph G;
    G.assign(N, vector<pair<int, int>>());
    for (int i = 1; i < N; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--;v--;
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }
    color.assign(N, -1);
    dfs(G, 0, 1);
    for (auto c: color) cout << c << endl;
    return 0;
}