#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i=(a); i<(b); i++)
#define REP(i, n) FOR(i, 0, n)
#define all(x) (x).begin(), (x).end()
#define bit(x) (1L << (x))
using ll = long long;
using namespace std;

class dep_union_find{
    int n_; 
    vector<int> par, rank, dep;

public:
    dep_union_find(int n): n_{n}, par(n), rank(n, 1), dep(n, 0){
        iota(par.begin(), par.end(), 0);
    } 

    bool same(int x, int y) {
        return find(x) == find(y);
    }

    // dep[y] = dep[x] + d
    bool unite(int x, int y, int d) {
        int rx = find(x), ry = find(y);
        if (rx == ry) {
            return false;
        }

        d = d + dep[x] - dep[y];

        if (rank[rx] < rank[ry]) {
            swap(rx, ry);
            d = -d;
        }

        if (rank[rx] == rank[ry]) ++rank[rx];

        par[ry] = rx;
        
        dep[ry] = d;

        return true;
    }

    int find(int x) {
        if(par[x] == x) {
            return x;
        } else {
            int r = find(par[x]);
            dep[x] += dep[par[x]];
            return par[x] = r;
        }
    }

    // dep[x] - dep[y]
    int diff(int x, int y) {
        if (find(x) != find(y)) {
            return -1;
        } else {
            return dep[x] - dep[y];
        }
    }

    void debug() const {
        for (int d : dep) cout << d << " ";
        cout << endl;
    }
};

int main() {
    int n, m; cin >> n >> m;

    dep_union_find uf(n);

    REP(_, m) {
        int l, r, d; cin >> l >> r >> d;
        --l; --r;

        if (!uf.same(l, r)) {
            uf.unite(l, r, d); // dep[r] = dep[l] + d
        } else {
            if (uf.diff(r, l) != d) { // dep[r] - dep[l] != d
                cout << "No" << endl;
                return 0;
            }
        }
    }

    cout << "Yes" << endl;
    
    return 0;
}
