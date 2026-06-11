#include <bits/stdc++.h>
using ll = long long;
using namespace std;

const int inf = 1e9;
const ll linf = 1e18;

class UnionFind
{
protected:
    vector<int> par;
    vector<int> rank;
    vector<int> sz;
    int _count;

public:
    UnionFind(int n) : par(n), rank(n, 0), sz(n, 1), _count(n) {
        iota(par.begin(), par.end(), 0);
    }

    virtual int find(int x) {
        if (par[x] == x) return x;
        else return par[x] = find(par[x]);
    }

    void unite(int x, int y) {
        x = find(x); y = find(y);
        if (x == y) return;

        _count--;
        if (rank[x] < rank[y]) {
            swap(x, y);
        }
        if (rank[x] == rank[y]) rank[x]++;

        par[y] = x; sz[x] += sz[y];
    }

    bool same(int x, int y) { return find(x) == find(y); }

    int size(int x) { return sz[find(x)]; }

    int count() { return _count; }
};

template <typename T>
class WeightedUnionFind : public UnionFind
{
private:
    vector<T> wt;

public:
    WeightedUnionFind(int n, T unity = 0) : UnionFind(n), wt(n, unity) {}

    int find(int x) override {
        if (par[x] == x) return x;
        else {
            int t = find(par[x]);
            wt[x] += wt[par[x]];
            return par[x] = t;
        }
    }
    
    int weight(int x) {
        find(x); return wt[x];
    }

    void unite(int x, int y, T w) {
        w += weight(x); w -= weight(y);
        x = find(x); y = find(y);
        if (x == y) return;

        _count--;
        if (rank[x] < rank[y]) {
            swap(x, y); w = -w;
        }
        if (rank[x] == rank[y]) rank[x]++;

        par[y] = x; sz[x] += sz[y]; wt[y] = w;
    }

    T diff(int x, int y) { return weight(y) - weight(x); }
};

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, m; cin >> n >> m;
    WeightedUnionFind<int> uf(n);
    for (int i = 0; i < m; i++) {
        int l, r, d; cin >> l >> r >> d; l--, r--; // 0-indexed
        if (!uf.same(l, r)) {
            uf.unite(l, r, d);
        } else {
            if (d != uf.diff(l, r)) {
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
    return 0;
}