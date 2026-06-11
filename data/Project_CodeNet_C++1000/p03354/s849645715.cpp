#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pli = pair<ll, int>;
using Graph = vector<vector<pii>>;
const int MOD = 1e9 + 7;

struct UnionFind {
    vector<int> par, rnk;

    UnionFind(int N) : par(N), rnk(N) {
        for (int i = 0; i < N; ++i)
            par[i] = i;
    }

    int root(int x) {
        return (par[x] == x ? x : par[x] = root(par[x]));
    }

    bool issame(int x, int y) {
        return root(x) == root(y);
    }

    void unite(int x, int y) {
        x = root(x), y = root(y);
        if (x == y)
            return;
        if (rnk[x] < rnk[y])
            swap(x, y);
        par[y] = x;
        if (rnk[x] == rnk[y])
            rnk[x]++;
    }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;
    vector<int> p(N);
    for (int i = 0; i < N; ++i) {
        cin >> p[i];
        p[i]--;
    }

    UnionFind uf(N);
    for (int i = 0; i < M; ++i) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        uf.unite(x, y);
    }

    int ans = 0;
    for (int i = 0; i < N; ++i)
        if (uf.issame(i, p[i]))
            ans++;

    cout << ans << endl;

    return 0;
}
