#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct UnionFindTree {
    vector<int> par, sz;
    int operator [](int x) { return find(x); }
    void build(int n) { par.assign(n, -1); sz.assign(n, 1); }
    int find(int x) { return par[x] < 0 ? x : (par[x] = find(par[x])); }
    bool same(int x, int y) { return find(x) == find(y); }
    int size(int x) { return sz[find(x)]; }
    bool unite(int x, int y) {
        if ((x = find(x)) == (y = find(y))) return 0;
        par[x] = min(par[x], par[y] - 1); sz[x] += sz[y]; par[y] = x; return 1;
    }
    bool uniteByRank(int x, int y) { return par[find(x)] > par[find(y)] ? unite(y, x) : unite(x, y); }
};

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> A(M), B(M);
    for (int i = 0; i < M; ++i) cin >> A[i] >> B[i], A[i]--, B[i]--;

    UnionFindTree uf;
    uf.build(N);

    vector<ll> ans(M, (ll)N * (N - 1) / 2);
    for (int i = M - 1; i > 0; --i) {
        ans[i - 1] = ans[i];
        if (!uf.same(A[i], B[i])) {
            int s = uf.size(A[i]), t = uf.size(B[i]);
            ans[i - 1] -= (ll)s * t;
            uf.uniteByRank(A[i], B[i]);
        }
    }

    for (ll x : ans) cout << x << endl;
}
