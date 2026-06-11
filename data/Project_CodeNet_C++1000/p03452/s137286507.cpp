#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; i++)
using namespace std;

class WeightedUnionFind {
public:
    WeightedUnionFind(int n) : parent(n), rank(n, 0), value(n, 0) {
        rep(i, 0, n) parent[i] = i;
    }

    int root(int x) {
        if (parent[x] == x) {
            return x;
        } else {
            int root_x = root(parent[x]);
            value[x] += value[parent[x]];
            return parent[x] = root_x;
        }
    }

    bool same(int x, int y) {
        return root(x) == root(y);
    }

    int weight(int x) {
        root(x);
        return value[x];
    }

    int diff(int x, int y) {
        return weight(y) - weight(x);
    }

    bool unite(int x, int y, int w) {
        w += weight(x);
        w -= weight(y);

        x = root(x);
        y = root(y);
        if (x == y) return false;

        if (rank[x] < rank[y]) {
            swap(x, y);
            w = -w;
        }

        if (rank[x] == rank[y]) rank[x]++;

        parent[y] = x;
        value[y] = w;
        
        return true;
    }

private:
    vector<int> parent, rank, value;
};

int main() {
    int n, m;
    cin >> n >> m;

    WeightedUnionFind uf(n);
    rep(i, 0, m) {
        int l, r, d;
        cin >> l >> r >> d;
        l--, r--;

        if (uf.same(l, r) && d != uf.diff(l, r)) {
            cout << "No" << endl;
            return 0;
        } else {
            uf.unite(l, r, d);
        }
    }
    
    cout << "Yes" << endl;
    return 0;
}