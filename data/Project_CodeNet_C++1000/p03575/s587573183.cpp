#include "bits/stdc++.h" 
using namespace std; 
typedef long long ll;

class UnionFind {
private:
    vector<int> par;
public:
    UnionFind(int n) {
        par.resize(n, -1);
    }
    int root(int x) {
        if (par[x] < 0) return x;
        return par[x] = root(par[x]);
    }
    bool unite(int x, int y) {
        int rx = root(x);
        int ry = root(y);
        if (rx == ry) return false;
        if (size(rx) < size(ry)) swap(rx, ry);
        par[rx] += par[ry];
        par[ry] = rx;
        return true;
    }
    bool same(int x, int y) {
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }
    int size(int x) {
        return -par[root(x)];
    }
};

int main() {
    int n,m;cin >> n >> m;
    vector<int> a(m),b(m);
    for (int i = 0; i < m; i++) {
        cin >> a[i] >> b[i];
        a[i]--;b[i]--;
    }
    int cnt = 0;
    for (int i = 0; i < m; i++) {
        UnionFind uf(n);
        for (int j = 0; j < m; j++) {
            if (i == j) continue;
            uf.unite(a[j],b[j]);
        }
        cnt += uf.size(0) != n;
    }
    cout << cnt << endl;
    return 0;
}