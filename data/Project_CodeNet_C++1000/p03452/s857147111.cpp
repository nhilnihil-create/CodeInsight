#include <bits/stdc++.h>
using namespace std;

using pint = pair<int, int>;
#define x first
#define y second

int n, m, v[100004], w[100004];
vector<pint> g[100004];

bool dfs(int k, int x) {
    if (v[k]) return w[k] == x;
    v[k] = true; w[k] = x;
    bool ret = true;
    for (pint i : g[k]) ret &= dfs(i.x, x + i.y);
    return ret;
}

int main() {
    cin >> n >> m;
    for (int i=0; i<m; i++) {
        int x, y, k;
        cin >> x >> y >> k;
        g[x].emplace_back(y, k);
        g[y].emplace_back(x, -k);
    }

    bool ans = true;
    for (int i=1; i<=n; i++) if (!v[i]) ans &= dfs(i, 0);

    cout << (ans ? "Yes" : "No");
}