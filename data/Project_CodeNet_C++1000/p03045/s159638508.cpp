#include <bits/stdc++.h>
using namespace std;

const int maxn = 100001;

vector < vector < pair < int, int > > > g(maxn);
vector < int > c(maxn, 0);

void paint (int u) { // paint the roses green huh?
    for (auto edge: g[u]) {
        int v = edge.first, z = edge.second;
        if (!c[v]) {
            if ((z && c[u] == 1) || (!z && c[u] == 2))
                c[v] = 2;
            else
                c[v] = 1;
            paint(v);
        }
    }
}

signed main () {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int x, y, z;
        cin >> x >> y >> z;
        g[x].push_back(make_pair(y, (z & 1)));
        g[y].push_back(make_pair(x, (z & 1)));
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (!c[i]) {
            c[i] = 1;
            paint(i);
            ++ans;
        }
    }
    cout << ans << '\n';
}
