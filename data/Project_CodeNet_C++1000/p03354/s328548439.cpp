#include <bits/stdc++.h>
using namespace std;

class UnionFind {
private:
    vector<int> par;
    vector<int> rank;

public:
    UnionFind(int n) {
        par.resize(n);
        rank.resize(n);
        for (int i = 0; i < n; i++) {
            par[i] = i;
            rank[i] = 0;
        }
    }

    int find(int x) {
        if (par[x] == x) {
            return x;
        }
        return par[x] = find(par[x]);
    }

    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return;

        if (rank[x] < rank[y]) {
            par[x] = par[y];
        } else {
            par[y] = par[x];
            if (rank[x] == rank[y]) rank[x]++;
        }
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }
};

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> P(N);
    for (int i = 0; i < N; i++) {
        cin >> P[i];
        P[i]--;
    }
    UnionFind uf = UnionFind(N);
    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        uf.unite(x, y);
    }

    int res = 0;
    for (int i = 0; i < N; i++) {
        if (uf.same(i, P[i])) res++;
    }

    cout << res << endl;
    return 0;
}