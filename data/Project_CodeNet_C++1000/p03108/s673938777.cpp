#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; i++)
#define rep2(i,a,n) for (int i = a; i < n; i++)
using namespace std;

// N island, M bridge
long long N, M;

// 橋のペア。生き残った順番にする。
vector<int> A;
vector<int> B;

// 答えが格納される
vector<long long> res;

struct UnionFind {
    vector<int> par;

    UnionFind(int n) : par(n, -1) { }
    void init(int n) { par.assign(n, -1); }

    int root(int x) {
        if (par[x] < 0) return x;
        else return par[x] = root(par[x]);
    }

    bool issame(int x, int y) {
        return root(x) == root(y);
    }

    bool merge(int x, int y) {
        x = root(x); y = root(y);
        if (x == y) return false;
        if (par[x] > par[y]) swap(x, y); // merge technique
        par[x] += par[y];
        par[y] = x;
        return true;
    }

    int size(int x) {
        return -par[root(x)];
    }
};

void init() {
    cin >> N >> M;
    rep(i, M) {
        int a, b; cin >> a >>b;
        a--; b--;
        A.push_back(a);
        B.push_back(b);
    }
    reverse(A.begin(), A.end());
    reverse(B.begin(), B.end());
}

void solve() {

    UnionFind uf(N);
    long long pre = N * (N - 1) / 2;

    rep(i, M) {
        res.push_back(pre);
        int f = A[i]; int s = B[i];
        if (uf.issame(f, s)) continue;

        long long diff = uf.size(f) * uf.size(s);
        pre -= diff;
        uf.merge(f, s);

    }

    reverse(res.begin(), res.end());

    for (auto r : res) {
        printf("%lld\n", r);
    }

}

int main() {
    init();
    solve();
    return 0;
}
