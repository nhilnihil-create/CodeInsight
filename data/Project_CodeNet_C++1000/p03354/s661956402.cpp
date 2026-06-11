#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct UnionFind {
    vector<int> data;
    int sz;
    UnionFind(int sz) : data(sz, -1), sz(sz) { }
    bool unionSet(int x, int y) {
        if ((x = root(x)) == (y = root(y))) return false;
        if (data[x] > data[y]) swap(x, y);
        data[x] += data[y]; data[y] = x; sz--;
        return true;
    }
    bool findSet(int x, int y) { return root(x) == root(y); }
    int root(int x) { return data[x] < 0 ? x : data[x] = root(data[x]); }
    int size(int x) { return -data[root(x)]; }
    int size() { return sz; }
};

int main() {
    int n, m; cin >> n >> m;
    vector<int> p(n);
    for (auto &pi: p) cin >> pi, pi--;
    UnionFind uf(n);
    while (m--) {
        int x, y; cin >> x >> y; x--, y--;
        uf.unionSet(x, y);
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) cnt += uf.root(i) == uf.root(p[i]);
    cout << cnt << endl;
    return 0;
}
