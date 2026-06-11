#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

struct Edge {
    int to;     // 辺の行き先
    int weight; // 辺の重み
    Edge(int t, int w) : to(t), weight(w) { }
};
using Graph = vector<vector<Edge>>;

vector<int> color;

vector<bool> seen;
void dfs(const Graph &G, int v, int dist) {
    seen[v] = true;
    if (dist % 2 == 0) {
	color[v] = 1;
    } else {
	color[v] = 0;
    }

    for (auto e : G[v]) {
        if (seen[e.to]) continue;
        dfs(G, e.to, dist + e.weight);
    }
}

int main() {
    // 頂点数と辺数
    int N, M;
    cin >> N;
    M = N - 1;

    // グラフ
    Graph G(N);
    for (int i = 0; i < M; ++i) {
        int from, to, weight;
        cin >> from >> to >> weight;
        G[from-1].push_back(Edge(to-1, weight));
	G[to-1].push_back(Edge(from-1, weight));
    }

    seen.assign(N, false);
    color.resize(N);
    
    dfs(G, 0, 0);

    for (int i = 0; i < N; i++) {
	cout << color[i] << endl;
    }
    return 0;
}

