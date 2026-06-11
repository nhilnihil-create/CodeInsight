#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
using Graph = vector<vector<int>>;
const int INT_INF = 1001001001;
//stoi(s) : string→int stoll(s) :string→longlong  int→string to_string(i)
const double PI = acos(-1.0);
//小数点の表し方 cout << fixed << setprecision(5);


class UnionFind {
public:
    vector < ll > par; // 各元の親を表す配列
    vector < ll > siz; // 素集合のサイズを表す配列(1 で初期化)

    // Constructor
    UnionFind(ll sz_): par(sz_), siz(sz_, 1) {
        for (ll i = 0; i < sz_; ++i) par[i] = i; // 初期では親は自分自身
    }
    void init(ll sz_) {
        par.resize(sz_);
        siz.assign(sz_, 1);
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

int main(){
    ll n,m;
    cin >> n >> m;
    vector<ll> a(m),b(m);
    UnionFind tree(n);
    for(int i=0;i<m;i++){
        cin >> a[i] >> b[i];
        a[i]--;
        b[i]--;
    }
    ll ans = n*(n-1) / 2;
    vector<ll> anse;
    for(ll i=0;i<m;i++){
        anse.push_back(ans);
        ll pa = a[m-i-1],pb = b[m-i-1];
        if(tree.issame(pa,pb)) continue;

        ll sa = tree.size(pa),sb = tree.size(pb);
        ans -= sa * sb;
        tree.merge(pa,pb);
    }
    reverse(anse.begin(),anse.end());
    for(int i=0;i<m;i++){
        cout << anse[i] << endl;
    }
}