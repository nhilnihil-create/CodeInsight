//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = int64_t;
using P = pair<int, int>;
using vs = vector<string>;
using vi = vector<int>;
using vvi = vector<vi>;

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
} uft(200000);

int main() {
    int n, m;
    cin >> n >> m;
    rep(i, m) {
        int x, y, z;
        cin >> x >> y >> z;
        --x;
        --y;
        if(!(z&1)) {
            uft.unite(2*x, 2*y);
            uft.unite(2*x+1, 2*y+1);
        } else {
            uft.unite(2*x+1, 2*y);
            uft.unite(2*x, 2*y+1);
        }
    }

    set<int> se;
    rep(i, 2*n) {
        se.insert(uft.root(i));
    }

    cout << ((int)se.size())/2 << endl;
}