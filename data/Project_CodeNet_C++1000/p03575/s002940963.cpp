#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < n; ++i)
typedef long long ll;
using namespace std;

struct UnionFind {
    vector<int> par, rnk, cnt;
    UnionFind(int N) : par(N), rnk(N), cnt(N) {
        for (int i = 0; i < N; i++) {
            par[i] = i;
            cnt[i] = 1;
        }
    }

    int root(int x) {
        if (par[x] == x)
            return x;
        return par[x] = root(par[x]);
    }

    void unite(int x, int y) {
        x = root(x), y = root(y);
        if (x == y)
            return;
        if (rnk[x] < rnk[y])
            swap(x, y);
        if (rnk[x] == rnk[y])
            rnk[x]++;
        par[y] = x;
        cnt[x] += cnt[y];
    }

    bool same(int x, int y) {
        return root(x) == root(y);
    }

    int rcnt(int x) {
        return cnt[root(x)];
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(m), b(m);
    rep(i, m) {
        cin >> a[i] >> b[i];
        a[i]--, b[i]--;
    }

    UnionFind uf(n);
    int ans = 0;
    rep(i, m) {
        UnionFind uf(n);
        rep(j, m) {
            if (j == i)
                continue;
            else
                uf.unite(a[j], b[j]);
        }
        if (uf.rcnt(0) < n)
            ans++;
    }

    cout << ans << endl;

    return 0;
}