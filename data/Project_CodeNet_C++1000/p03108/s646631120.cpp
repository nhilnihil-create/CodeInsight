//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = int64_t;
using P = pair<int, int>;
using vs = vector<string>;
using vi = vector<ll>;
using vvi = vector<vi>;
const int INF = 100010001;
const ll LINF = (ll)INF*INF*10;

struct UnionFind {
    vector<int> par; // 親を指すvector,-par[親]は木のサイズ
    UnionFind(int n):par(n, -1) {} // uniteで親を埋め込んでいく必要あり
    int root(int x) { // 親をたどる&データの整理
        if(par[x] < 0) return x;
        return par[x] = root(par[x]);
    }
    bool unite(int x, int y) { // データの結合
        x = root(x);
        y = root(y);
        if(x == y) return false;
        if(par[x] > par[y]) swap(x, y);
        par[x] += par[y];
        par[y] = x;
        return true;
    }
    bool same(int x, int y) {return root(x) == root(y);} // 所属判定
    int size(int x) {return -par[root(x)];} // 木のサイズ
}uft(100000);

struct edge{
    int from, to;
    edge(int a=0, int b=0):from(a), to(b) {}
};

// サイズ,辺の情報,初期化の必要あり
vector<edge> es;


int main() {
    ll n, m;
    cin >> n >> m;
    es.resize(m);
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        es[i] = edge(a-1, b-1);
    }

    vi ans(m);

    reverse(all(es));
    rep(i, m-1) {
        edge e = es[i];
        ans[i+1] = ans[i];
        if(uft.same(e.from, e.to)) continue;
        ll now = uft.size(e.from);
        now *= uft.size(e.to);
        ans[i+1] += now;
        uft.unite(e.from, e.to);
    }

    reverse(all(ans));

    rep(i, m) {
        cout << n*(n-1)/2 - ans[i] << endl;
    }
}  