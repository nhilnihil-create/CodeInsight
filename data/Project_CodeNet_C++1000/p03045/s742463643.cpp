#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define INF 1000000000000000000

class UnionFind {
  public:
    vector<ll> par; // 各元の親を表す配列
    vector<ll> siz; // 素集合のサイズを表す配列(1 で初期化)

    // Constructor
    UnionFind(ll sz_) : par(sz_), siz(sz_, 1) {
        for (ll i = 0; i < sz_; ++i)
            par[i] = i; // 初期では親は自分自身
    }
    void init(ll sz_) {
        par.resize(sz_);
        siz.assign(sz_, 1);
        for (ll i = 0; i < sz_; ++i)
            par[i] = i; // 初期では親は自分自身
    }

    // Member Function
    // Find
    ll root(ll x) { // 根の検索
        while (par[x] != x) {
            x = par[x] = par[par[x]]; // x の親の親を x の親とする
        }
        return x;
    }

    // Union(Unite, Merge)
    bool merge(ll x, ll y) {
        x = root(x);
        y = root(y);
        if (x == y)
            return false;
        // merge technique（データ構造をマージするテク．小を大にくっつける）
        if (siz[x] < siz[y])
            swap(x, y);
        siz[x] += siz[y];
        par[y] = x;
        return true;
    }

    bool issame(ll x, ll y) { // 連結判定
        return root(x) == root(y);
    }

    ll size(ll x) { // 素集合のサイズ
        return siz[root(x)];
    }
};

int main() {
    int N, M;
    cin >> N >> M;
    UnionFind tree(N);

    rep(i, M) {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        tree.merge(a, b);
    }

    set<int> pars;
    rep(i, N) { pars.insert(tree.root(i)); }

    cout << pars.size() << endl;
}
