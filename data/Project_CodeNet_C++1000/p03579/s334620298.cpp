#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> g;
vector<int> color;
bool dfs(int u, int p, int c) {
    if (~color[u]) return color[u] != color[p];
    color[u] = c;
    for (int v: g[u]) if (v != p) if (!dfs(v, u, c ^ 1)) return false;
    return true;
}

int main() {
    int n, m; cin >> n >> m;
    g.resize(n);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b; a--, b--;
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }
    color.assign(n, -1);
    long long all = 0;
    if (!dfs(0, -1, 0)) {
        all = 1LL * n * (n - 1) / 2;
    } else {
        for (int i = 0; i < n; i++) all += color[i];
        all *= n - all;
    }
    cout << all - m << endl;
    return 0;
}
