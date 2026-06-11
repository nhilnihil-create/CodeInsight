#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> e(n);
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        e[a].push_back(b);
        e[b].push_back(a);
    }
    vector<int> depth(n);
    function<void(int, int)> dfs = [&](int v, int p) {
        for (int u: e[v]) {
            if (u != p) {
                depth[u] = depth[v] + 1;
                dfs(u, v);
            }
        }
    };
    dfs(0, -1);
    int deepest = max_element(depth.begin(), depth.end()) - depth.begin();
    depth.assign(n, 0);
    dfs(deepest, -1);
    int diam = *max_element(depth.begin(), depth.end());
    if (diam % 3 == 1) {
        cout << "Second\n";
    } else {
        cout << "First\n";
    }
    return 0;
}
