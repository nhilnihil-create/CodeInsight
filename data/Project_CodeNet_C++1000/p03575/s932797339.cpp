#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; i++)
#define rep2(i,a,n) for (int i = a; i < n; i++)
using namespace std;
int N, M;
vector<pair<int, int>> P;

struct UnionFind {
    vector<int> par;

    UnionFind(int N): par(N) {
        rep(i, N) par[i] = i;
    }

    int root(int x) {
        if (par[x] == x) return x;
        return par[x] = root(par[x]);
    }

    bool same(int x, int y) {
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }

    void unite(int x, int y) {
        int rx = root(x);
        int ry = root(y);

        if (same(rx, ry)) return;

        par[rx] = ry;
    }

};


void init() {
    cin >> N >> M;

    rep(i, M) {
        int a, b; cin >> a >> b;
        a--; b--;
        P.push_back({a, b});
    }

}

void solve() {
    int res =0;
    rep(de, M) {
        bool flag = false;
        UnionFind uf(N);
        rep(i, M) {
            if (i == de) continue;
            uf.unite(P[i].first, P[i].second);
        }
        int stad = 0;
        for (int i = 1; i < N; i++) {
            if (!uf.same(stad, i)) flag = true;
        }

        if (flag) res++;
    }

    printf("%d\n", res);
}

int main() {
    init();
    solve();
    return 0;
}
