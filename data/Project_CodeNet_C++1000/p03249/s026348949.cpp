#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#define N 100100
#define pii pair<ll, int>
using namespace std;
typedef long long ll;

int n, sz[N], fa[N];
pii p[N];
vector<int> G[N];

void dfs(int u, int d, ll &res) {
    res += d;
    for (auto v : G[u])
        dfs(v, d + 1, res);
}

int main() {
#ifdef isLOCAL
    freopen("work.in", "r", stdin);
    freopen("work.out", "w", stdout);
#endif

    cin >> n;

    for (int i = 1; i <= n; ++i) {
        long long d;
        scanf("%lld", &d);
        p[i] = make_pair(d, i);
    }

    sort(p + 1, p + n + 1);

    for (int i = n; i > 1; --i) {
        int u = p[i].second, szp;
        ++sz[u], szp = n - sz[u];
        ll tmp = p[i].first + n - 2 * szp;
        int pos = lower_bound(p + 1, p + n + 1, make_pair(tmp, 0)) - p;
        pii now = p[pos];
        if (pos >= i || now.first != tmp) return puts("-1"), 0;
        sz[fa[u] = now.second] += sz[u];
        G[fa[u]].push_back(u);
    }

    int rt = p[1].second;
    ll tmp = 0;
    dfs(rt, 0, tmp);
    if (tmp != p[1].first) return puts("-1"), 0;

    for (int i = n; i > 1; --i)
        printf("%d %d\n", p[i].second, fa[p[i].second]);

    return 0;
}
