//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; ++i)
using namespace std;
using ll = int64_t;
using vi = vector<int>;
using vvi = vector<vi>;

struct unionFind {
    vector<int> par; // 親を指すvector,-par[親]は木のサイズ
    unionFind(int n):par(n, -1) {} // 自分で親を埋め込んでいく必要あり
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
} uft(100000);

int main() {
    int n, m;
    cin >> n >> m;
    vi vec(n), vec_(n);
    rep(i, n) {
        cin >> vec[i];
        --vec[i];
        vec_[vec[i]] = i;
    }
    rep(i, m) {
        int x, y;
        cin >> x >> y;
        --x;
        --y;
        uft.unite(x, y);
    }

    int ans=0;
    rep(i, n) {
        if(uft.same(i, vec_[i])) ans++;
    }

    cout << ans << endl;
}