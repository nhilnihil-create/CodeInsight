#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define all(x) (x).begin(),(x).end()
template <class T> inline bool chmin(T &a, T b) {if (a > b){a = b;return true;}return false;}
template <class T> inline bool chmax(T &a, T b) {if (a < b){a = b;return true;}return false;}

class UnionFind {
public:
    vector <ll> par; // 各元の親を表す配列
    vector <ll> siz; // 素集合のサイズを表す配列(1 で初期化)
    ll ans;

    // Constructor
    UnionFind(ll sz_): par(sz_), siz(sz_, 1LL) {
        for (ll i = 0; i < sz_; ++i) par[i] = i; // 初期では親は自分自身
        ans = sz_*(sz_-1)/2;
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

        // 回答更新
        ll p=siz[x], q=siz[y];
        ans = ans + (p*(p-1))/2 + (q*(q-1))/2 - ((p+q)*(p+q-1))/2;

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


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n,m;cin>>n>>m;
    vector<pair<ll,ll>> ab(m);
    rep(i,m){
        cin>>ab[i].first;
        cin>>ab[i].second;
    }
    reverse(all(ab));
    UnionFind tree(n);

    vector<ll> ans;
    ans.push_back(n*(n-1)/2);
    for(auto t : ab){
        tree.merge(t.first-1, t.second-1);
        ans.push_back(tree.ans);
    }

    reverse(all(ans));
    for(int i=1; i<=m; i++){
        cout<<ans[i]<<endl;
    }
    return 0;
}