#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;

struct UnionFind {
    vector<int> par;

    //正の場合、親を表す
    //負の場合、根で数値は連結成分のサイズ
    UnionFind(int n) : par(n, -1) {}

    int root(int x) {
        if (par[x] < 0) {
            return x;
        } else {
            return par[x] = root(par[x]); //経路圧縮
        }
    }

    bool unite(int x, int y) {
        x = root(x); y = root(y);

        if (x == y) return false;
        if (par[x] > par[y]) swap(x, y); //小さい方を大きい方にくっつけるため

        par[x] += par[y];
        par[y] = x;

        return true;
    }

    bool same(int x, int y) {
        return root(x) == root(y);
    }

    int size(int x) {
        return -par[root(x)];
    }
};

int main() {

    int n, m; cin >> n >> m;

    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        p[i]--;
    }

    UnionFind tree(n);

    for (int i = 0; i < m; ++i) {
        int x, y; cin >> x >> y;
        --x; --y;
        tree.unite(x, y);
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (tree.same(p[i], i)) {
            ++ans;
        }
    }

    cout << ans << endl;
}