#include <bits/stdc++.h>
using namespace std;

#define rp(i, k, n) for (int i = k; i < n; i++)
typedef long long ll;
typedef double ld;

template<class T>inline bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>inline bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll INF = 1ll << 60;
const ll MOD = 1e9 + 7ll;
const double PI=3.14159265358979323846;

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
    ll n, m;
    cin >> n >> m;
    vector<pair<int, int>> path;
    rp(i, 0, m) {
        int a, b;
        cin >> a >> b;
        path.emplace_back(a, b);
    }

    UnionFind UF(n+10);
    vector<ll> res(m+10);
    res[m-1] = n*(n-1) / 2ll;
    for(int i = m-1; i >= 1; i--) {
        int a = path[i].first;
        int b = path[i].second;
        // aとbのグループのサイズをもらう
        ll a_size = UF.size(a);
        ll b_size = UF.size(b);
        // aとbをくっつける
        if(UF.merge(a, b)){
            // res更新
            ll ab_size = a_size + b_size;
            res[i-1] = res[i] - ab_size * (ab_size-1) / 2ll + a_size * (a_size-1) / 2ll + b_size * (b_size-1) / 2ll;
        }
        else res[i-1] = res[i];
        // printf("a = %d b = %d a_size = %lld b_size = %lld res = %lld\n", a, b, a_size, b_size, res[i-1]);
    }
    rp(i, 0, m) {
        cout << res[i] << endl;
    }
    return 0;
}
