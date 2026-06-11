#include <iostream>
#include <vector>
#include <set>
using namespace std;
#define rep(i, n) for (int i=0; i<(n); ++i)

struct UnionFind {
    vector<int> par;
    vector<int> rank;
    UnionFind (int n) {
        par.resize(n, -1);
        rank.resize(n, 1);
    }
    int root (int n) {
        if (par[n] == -1) return n;
        return par[n] = root(par[n]);
    }
    void unite (int n, int m) {
        n = root(n);
        m = root(m);
        if (n == m) return;
        if (rank[n] < rank[m]) {
            par[n] = m;
        } else {
            par[m] = n;
            if (rank[n] == rank[m]) {
                rank[n]++;
            }
        }
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> edge(m);
    rep(i, m) {
        int a, b; cin >> a >> b;
        a--; b--;
        edge[i] = make_pair(a, b);
    }
    int ans = 0;
    rep(i, m) {
        UnionFind uf(n);
        rep(j, m) {
            if (i == j) continue;
            uf.unite(edge[j].first, edge[j].second);
        }
        set<int> roots;
        rep(j, n) roots.insert(uf.root(j));
        if (roots.size() > 1) ans++;
    }
    cout << ans << endl;
}