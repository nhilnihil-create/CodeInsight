#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
#define mod 1000000007
#define MAXN 100001
#define MAXM 100005
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
UnionFind tree(MAXN);
ll conv[MAXM];
int a[MAXM];
int b[MAXM];
int main() {
    int n, m;
    cin >> n >> m;
    conv[10001] = 0;
    for (int i = 1; i <= m; i++) {
        cin >> a[i] >> b[i];
    }
    for (int i = m; i >= 1; i--) {
        if (tree.issame(a[i], b[i])) {
            conv[i] = conv[i + 1];
        }
        else {
            conv[i] = conv[i + 1] + tree.size(a[i]) * tree.size(b[i]);
            tree.merge(a[i], b[i]);
        }
    }
    for (int i = 2; i <= m + 1; i++) {
        cout << conv[1] - conv[i] << endl;
    }
    return 0;
}