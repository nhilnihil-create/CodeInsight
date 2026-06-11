#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int from, to, len;
    Edge(int from, int to, int len) : from(from), to(to), len(len) {}
};

vector<vector<Edge>> graph;
vector<int> ans;

void dfs(int v, int c = 0, int p = -1) {
    ans.at(v) = c;
    for (auto e : graph.at(v)) {
        if (e.to == p) continue;
        if (e.len % 2 == 0)
            dfs(e.to, c, v);
        else
            dfs(e.to, 1 - c, v);
    }
}

int main() {
    int N;
    cin >> N;
    graph = vector<vector<Edge>>(N);
    ans = vector<int>(N);
    for (int i = 0; i < N - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        --u;
        --v;
        graph.at(u).push_back(Edge(u, v, w));
        graph.at(v).push_back(Edge(v, u, w));
    }
    dfs(0);
    for (int i = 0; i < N; i++) {
        cout << ans.at(i) << endl;
    }

    return 0;
}
