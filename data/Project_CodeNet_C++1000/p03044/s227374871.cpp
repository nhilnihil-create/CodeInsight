#include "bits/stdc++.h"

using namespace std;
using Graph = vector<vector<pair<int, int>>>;

// field.assign(H, vector<int>(W, 0));
int N;
bool visited[100005];
bool setcolor[100005];

void dfs(const Graph &G, int v, bool is_white) {
    visited[v] = true;
    setcolor[v] = is_white;
    for (auto edge : G[v]) {
        int next_v = edge.first;
        int weitht = edge.second;
        if (visited[next_v]) continue;
        bool color = weitht & 1 ? !is_white : is_white;
        dfs(G, edge.first, color);
    }
}

void solve() {
    cin >> N;
    Graph G(N);
    memset(visited, 0, sizeof(visited));
    for (int i = 0; i < N - 1; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        u -= 1;
        v -= 1;
        G[u].push_back(make_pair(v, w));
        G[v].push_back(make_pair(u, w));
    }

    dfs(G, 0, true);
    // 頂点0を白
    // 全域木だからdfsは1回

    for (int i = 0; i < N; ++i)
        cout << (setcolor[i] ? 0 : 1) << endl;
}


int main() {
    solve();
}