#include<bits/stdc++.h>

using namespace std;

#define int long long
#define pb push_back
#define fi first
#define se second
typedef pair<int, int> ii;

const int N = 1e5 + 5;
int n, nChild[N], up[N], down[N];
vector<ii> d;
vector<int> gr[N], ver;

void dfs1 (int u, int p) {
    for (int v : gr[u]) if (v != p) {
        dfs1(v, u);
        down[u] += down[v] + nChild[v];
    }
}

void dfs2 (int u, int p) {
    for (int v : gr[u]) if (v != p) {
        up[v] = up[u] + down[u] - down[v] - nChild[v] + n - nChild[v];
        dfs2(v, u);
    }
}

signed main () {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int _ = 1; _ <= n; ++_) {
        nChild[_] = 1;
        int D; cin >> D;
        d.pb(ii(D, _) );
    }
    sort(d.begin(), d.end() );

    for (int i = d.size() - 1; i > 0; --i) {
        int u = d[i].se;
        int pos = lower_bound(d.begin(), d.end(), ii(d[i].fi - n + 2 * nChild[u], 0) ) - d.begin();
        if (pos == n || d[pos].fi != d[i].fi - n + 2 * nChild[u]) return cout << -1, 0;
        int v = d[pos].se;
        gr[u].pb(v); gr[v].pb(u);
        nChild[v] += nChild[u];
    }

    dfs1(d[0].se, 0);
    dfs2(d[0].se, 0);
    for (auto _ : d) {
        if (_.fi != up[_.se] + down[_.se]) return cout << -1, 0;
    }

    for (int i = 1; i <= n; ++i) {
        for (int j : gr[i]) if (i > j) cout << i << ' ' << j << '\n';
    }

    return 0;
}
