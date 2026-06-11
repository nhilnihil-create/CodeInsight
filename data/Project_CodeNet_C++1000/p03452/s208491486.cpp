// common include
#include <bits/stdc++.h>
using namespace std;

// global variables
#define debug(x) cout << #x << ": " << x << endl
typedef long long ll;
const int M = 1e9 + 7;
const int INF = 1e9;

// typedef
typedef pair<int, int> P;
// sort by P.first (asd)
bool comPair(const P &firstElof, const P &secondElof) {
    return firstElof.first < secondElof.first;
}

// moving 4-direction
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

#define MAX_N 100000 //10^5

template <class Abel>
struct UnionFind {
    vector<int> par;
    vector<int> rank;
    vector<Abel> diff_weight;

    UnionFind(int n = 1, Abel SUM_UNITY = 0) {
        init(n, SUM_UNITY);
    }

    void init(int n = 1, Abel SUM_UNITY = 0) {
        par.resize(n);
        rank.resize(n);
        diff_weight.resize(n);
        for (int i = 0; i < n; ++i)
            par[i] = i, rank[i] = 0, diff_weight[i] = SUM_UNITY;
    }

    int root(int x) {
        if (par[x] == x) {
            return x;
        } else {
            int r = root(par[x]);
            diff_weight[x] += diff_weight[par[x]];
            return par[x] = r;
        }
    }

    Abel weight(int x) {
        root(x);
        return diff_weight[x];
    }

    bool issame(int x, int y) {
        return root(x) == root(y);
    }

    bool merge(int x, int y, Abel w) {
        w += weight(x);
        w -= weight(y);
        x = root(x);
        y = root(y);
        if (x == y) return false;
        if (rank[x] < rank[y]) swap(x, y), w = -w;
        if (rank[x] == rank[y]) ++rank[x];
        par[y] = x;
        diff_weight[y] = w;
        return true;
    }

    Abel diff(int x, int y) {
        return weight(y) - weight(x);
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    UnionFind<int> uf(n);
    for (int i = 0; i < m; i++) {
        int l, r, d;
        cin >> l >> r >> d;
        l--;
        r--;
        if (uf.issame(l, r)) {
            if (uf.diff(l, r) != d) {
                cout << "No" << endl;
                return 0;
            }
        } else {
            uf.merge(l, r, d);
        }
    }
    cout << "Yes" << endl;
}
