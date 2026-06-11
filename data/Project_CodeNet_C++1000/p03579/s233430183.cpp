#include <algorithm>
#include <iostream>
#include <vector>
#include <functional>
using namespace std;

using UnWeightedGraph = vector<vector<int>>;
int is_bipartite(UnWeightedGraph &g) {
    int n = g.size();
    vector<int> color(n, -1);
    int cntW = 0;
    function<bool(int, int)> dfs = [&](int u, int c) {
        if ((color[u] = c) > 0) cntW++;
        for (int &v: g[u]) {
            if (color[v] == c) return false;
            if (color[v] < 0 && !dfs(v, 1 - c)) return false;
        }
        return true;
    };
    if (!dfs(0, 0)) return -1;
    return cntW;
}

int main() {
    int V, E; cin >> V >> E;
    UnWeightedGraph g(V);
    for (int i = 0; i < E; i++) {
        int a, b; cin >> a >> b; a--, b--;
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }
    int cntW = is_bipartite(g);
    if (cntW < 0) {
        cout << (1LL * V * (V - 1) / 2 - E) << endl;
    } else {
        int cntB = V - cntW;
        cout << (1LL * cntB * cntW - E) << endl;
    }
    return 0;
}