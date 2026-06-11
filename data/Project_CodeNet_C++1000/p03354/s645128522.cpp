#include <iostream>
#include <vector>
using namespace std;
#define rep(i, n) for (int i=0; i<(n); ++i)

struct UnionFind {
    vector<int> par;
    vector<int> rank;
    UnionFind (int n) {
        par.resize(n, -1);
        rank.resize(n, 1);
    }
    int find (int a) {
        if (par[a] == -1) return a;
        return par[a] = find(par[a]);
    }
    void unite (int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return;
        if (rank[a] < rank[b]) {
            par[a] = b;
        } else {
            par[b] = a;
            if (rank[a] == rank[b]) {
                rank[a]++;
            }
        }
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    UnionFind uf(n);
    vector<int> p(n);
    rep(i, n) {
        cin >> p[i];
        p[i]--;
    }
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        uf.unite(a, b);
    }
    int ans = 0;
    rep(i, n) {
        if (p[i] == i) ans++;
        else if (uf.find(i) == uf.find(p[i])) ans++;
    }
    cout << ans << endl;
}