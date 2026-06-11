#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

// union by size + path having
class UnionFind {
public:
    vector <ll> par; // 各元の親を表す配列
    vector <ll> siz; // 素集合のサイズを表す配列(1 で初期化)

    // Constructor
    UnionFind(ll sz_): par(sz_), siz(sz_, 1LL) {
        for (ll i = 0; i < sz_; ++i) par[i] = i; // 初期では親は自分自身
    }
    void init(ll sz_) {
        par.resize(sz_);
        siz.assign(sz_, 1LL);  // resize だとなぜか初期化されなかった
        for (ll i = 0; i < sz_; ++i) par[i] = i; // 初期では親は自分自身
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
        if (x == y) return false;
        // merge technique（データ構造をマージするテク．小を大にくっつける）
        if (siz[x] < siz[y]) swap(x, y);
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
    ll N, M; cin >> N >> M;
    vector<int> A(M);
    vector<int> B(M);
    rep(i, M){
        cin >> A[i] >> B[i];
        A[i]--; B[i]--;
    }

    UnionFind U = UnionFind(N);

    vector<ll> ans(M+1);
    ll f = (N * (N-1)) / 2;
    ans[M] = f;

    rep(i, M){
        int a = A[M-1-i];
        int b = B[M-1-i];

        ll as = U.size(a);
        ll bs = U.size(b);

        if(U.merge(a, b)){
            ans[M-1-i] = ans[M-i] - as*bs;
        } else {
            ans[M-1-i] = ans[M-i];
        }

    }

    for (int i = 1; i <= M; i++){
        cout << ans[i] << endl;
    }

    return 0;
}