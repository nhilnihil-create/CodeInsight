#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    cin.tie(0); ios::sync_with_stdio(false);

    int n, m;
    string s;

    cin >> n >> m >> s;
    vector<vector<int>> adj(n);
    vector<int> deg_a(n), deg_b(n);
    for (int i = 0, u, v; i < m; ++i) {
        cin >> u >> v;
        adj[u - 1].push_back(v - 1);
        adj[v - 1].push_back(u - 1);
        if (s[v - 1] == 'A') ++deg_a[u - 1];
        else ++deg_b[u - 1];
        if (s[u - 1] == 'A') ++deg_a[v - 1];
        else ++deg_b[v - 1];
    }

    int size = 0;
    queue<int> rm;
    for (int v = 0; v < n; ++v)
        if (deg_a[v] == 0 || deg_b[v] == 0) {
            ++size;
            rm.push(v);
        }

    while (!rm.empty()) {
        const int v = rm.front(); rm.pop();
        for (auto u : adj[v]) {
            if (deg_a[u] == 0 || deg_b[u] == 0) continue;

            if (s[v] == 'A') {
                --deg_a[u];
                if (deg_b[u] != 0 && deg_a[u] == 0) {
                    rm.push(u);
                    ++size;
                }
            }
            else {
                --deg_b[u];
                if (deg_a[u] != 0 && deg_b[u] == 0) {
                    rm.push(u);
                    ++size;
                }
            }
        }
    }

    if (size == n) cout << "No\n";
    else cout << "Yes\n";

    return 0;
}
