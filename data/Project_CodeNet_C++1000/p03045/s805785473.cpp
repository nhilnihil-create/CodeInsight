#include <bits/stdc++.h>
using namespace std;

struct UnionFind {
    vector<int> par;

    UnionFind(int N) : par(N) {
        for(int i = 0; i < N; i++) par[i] = i;
    }

    int root(int x) {
        if (par[x] == x) return x;
        return par[x] = root(par[x]);
    }

    void unite(int x, int y) {
        int rx = root(x);
        int ry = root(y);
        if (rx == ry) return;
        par[rx] = ry;
    }

    bool same(int x, int y) {
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }
};

int main() {
    int n, m, x, y, z;
    cin >> n >> m;
    UnionFind uf(n);
    for(int i = 0; i < m; ++i) {
        cin >> x >> y >> z;
        x--, y--;
        uf.unite(x, y);
    }
    int ans = 0;
    for(int i = 0; i < n; ++i) {
        if(uf.root(i) == i) ans++;
    }
    cout << ans << '\n';

    return 0;
}
