#include<bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (int)(n); i++)
#define sum(a) accumulate(a.begin(),a.end(),0LL)
#define put(i) cout<<fixed<<i<<endl
using namespace std;
using ll = long long;

//不便さの数え方が分からなくて解説見た

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

ll Combination(ll n, ll r) {
    ll num = 1;
    for (ll i = 1; i <= r; i++) {
        num = num * (n - i + 1) / i;
    }
    return num;
}


int main(){
    ll n, m; cin >> n >> m;
    vector<ll> a(m), b(m);
    rep(i,m) cin >> a[i] >> b[i];

    vector<ll> ans;
    ll com = Combination(n,2);

    UnionFind UF(n+1);
    for(long long i = m-1; i >= 0; i--){
        ll cnt = com;

        ans.push_back(com);

        if(!UF.issame(a[i],b[i])){
            com -= UF.size(a[i]) * UF.size(b[i]);
        }
        UF.merge(a[i],b[i]);
    }
    reverse(ans.begin(),ans.end());
    for(auto x:ans) put(x);
}