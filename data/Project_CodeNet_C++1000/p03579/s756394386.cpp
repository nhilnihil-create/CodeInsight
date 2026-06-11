#include <algorithm>
#include <iostream>
#include <vector>
#include <functional>
using namespace std;

int is_bipartite(vector<vector<int>> &g) {
    int cntW = 0;
    vector<int> color(g.size(), -1);
    function<bool(int, int)> dfs = [&](int u, int c) {
        if ((color[u] = c) > 0) cntW++;
        for (int v: g[u]) {
            if (color[v] == c) return false;
            if (color[v] < 0 && !dfs(v, 1 - c)) return false;
        }
        return true;
    };
    if (!dfs(0, 0)) return -1;
    return cntW;
}

int main() {
    int n, m; cin >> n >> m;
    vector<vector<int>> g(n);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b; a--, b--;
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }
    int cntW = is_bipartite(g);
    long long all = 0;
    if (cntW < 0) {
        all = 1LL * n * (n - 1) / 2;
    } else {
        all = 1LL * cntW * (n - cntW);
    }
    cout << all - m << endl;
    return 0;
}
