#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int n, m;
int x[100005], y[100005];
ll ans[100005];
 
struct UnionFind {
    vector<int> par;
    
    UnionFind(int n) : par(n, -1) { }
 
    int root(int x) {
        if (par[x] < 0) return x;
        else return par[x] = root(par[x]);
    }
    
    bool issame(int x, int y) {
        return root(x) == root(y);
    }
    
    bool merge(int x, int y) {
        x = root(x); y = root(y);
        if (x == y) return false;
        if (par[x] > par[y]) swap(x, y);
        par[x] += par[y];
        par[y] = x;
        return true;
    }
    
    int size(int x) {
        return -par[root(x)];
    }
};
 
int main() {
    cin >> n >> m;
    UnionFind uf(n);
    for (int i = 0; i < m; i++) {
        cin >> x[i] >> y[i];
        x[i]--; y[i]--;
    }
    ll res = 1ll*n*(n-1)/2;
    for (int i = m; i >= 0; i--) {
        ans[i] = res;
        if (uf.root(x[i]) == uf.root(y[i])) {
            continue;
        }
        else res -= 1ll*uf.size(x[i])*uf.size(y[i]);
        uf.merge(x[i], y[i]);
    }
    for (int i = 0; i < m; i++) cout << ans[i] << endl;
    return 0;
}