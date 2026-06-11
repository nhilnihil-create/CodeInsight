#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct UnionFind {
    vector<int> d;

    UnionFind(int n): d(n,-1) {}

    int root(int x) {
        if (d[x] < 0) return x;
        return d[x] = root(d[x]);
    }

    bool unite(int x, int y) {
        x = root(x); y = root(y);
        if (x == y) return false;
        if (d[x] > d[y]) swap(x,y);
        d[x] += d[y];
        d[y] = x;
        return true;
    }

    bool same(int x, int y) { return root(x) == root(y);}

    int size(int x) { return -d[root(x)];}
};

int main() {
    int n, m; cin >> n >> m;
    vector<int> a(m), b(m);
    for (int i = 0; i < m; i++) {
        cin >> a[i] >> b[i];
        a[i]--; b[i]--;
    }

    int ans = 0;
    for (int i = 0; i < m; i++) {
        UnionFind uf = UnionFind(n);
        for (int j = 0; j < m; j++) {
            if (j == i) continue;           
            uf.unite(a[j], b[j]);
        }

        if (uf.size(1) != n) ans++;
    }
    cout << ans << endl;
}
