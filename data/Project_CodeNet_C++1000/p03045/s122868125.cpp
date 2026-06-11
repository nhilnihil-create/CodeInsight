#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

struct UnionFind {
    vector<int> d;
    UnionFind(int n): d(n, -1) {}
    int root(int x) {
        if (d[x] < 0) return x;
        return d[x] = root(d[x]);
    }
    bool unite(int x, int y) {
        x = root(x); y = root(y);
        if (x == y) return false;
        if (d[x] > d[y]) swap(x, y);
        d[x] += d[y];
        d[y] = x;
        return true;
    }
    bool same(int x, int y) { return root(x) == root(y); }
    int size(int x) { return -d[root(x)]; }
};

int main() {
    int n, m;
    cin >> n >> m;
    UnionFind uf(n);
    int ans = n;
    for (int i = 0, x, y, z; i < m; i++) {
        cin >> x >> y >> z;
        x--; y--;
        if (uf.unite(x, y)) ans--;
    }
    cout << ans << endl;
}