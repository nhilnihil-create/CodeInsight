#include <bits/stdc++.h>

#define int long long

using namespace std;

typedef pair<int, int> pii;

const int MAXN = 100 * 1000 + 123;








int n, m, f[MAXN];
bool mark[MAXN];
vector<pii> g[MAXN];

void dfs(int);

int32_t main() {
    memset(f, 15, sizeof f);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int l, r, d;
        cin >> l >> r >> d;
        g[--l].push_back({--r, d}), g[r].push_back({l, -d});
    }
    for (int i = 0; i < n; i++)
        if (!mark[i])
            dfs(i);
    for (int i = 0; i < n; i++)
        for (auto ss : g[i]) {
            int u, x;
            tie(u, x) = ss;
            if (f[u] != f[i] + x)
                return cout << "No", 0;
        }
    cout << "Yes";
    return 0;
}
void dfs(int v) {
    mark[v] = true;
    for (auto ss : g[v]) {
        int u, q;
        tie(u, q) = ss;
        if (!mark[u]) {
            f[u] = f[v] + q;
            dfs(u);
        }
    }
}