#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

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
    int N, M; cin >> N >> M;
    vector<int> a(M);
    vector<int> b(M);
    rep(i, M){
        cin >> a[i] >> b[i];
    }
    UnionFind U(N+1);

    int ans = 0;
    rep(i, M){
        U.init(N+1);
        rep(j, M){
            if(j == i)continue;
            int x = a[j];
            int y = b[j];
            U.merge(x, y);
        }
        bool ok = true;
        for (int k = 1; k <= N; k++){
            for (int l = k; l <= N; l++){
                if(!U.issame(k, l)){
                    ok = false;
                }
            }
        }
        if(!ok){
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}