#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
using ll = long long;

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
    ll N, M;
    cin >> N >> M;

    vector<vector<int>> data(M, vector<int>(2));//input　　

    for(int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        data[i][0] = a;
        data[i][1] = b;
        //cout << data[i][0] << " " << data[i][1]<< endl;
    }
  
    vector<ll> ans(M + 1);
    ll zero = 0;
    ans[M] = N * (N - 1) / 2;
    //cout << ans[M]<<" " << N << " "<<N * (N - 1) << endl;
  
    UnionFind tree(N + 1);
      
    for (int i = M - 1; i >= 0; i--) {
      ll one, two;
      one = tree.size(data[i][0]);
      two = tree.size(data[i][1]);
      if (tree.issame(data[i][0], data[i][1])){
        ans[i] = ans[i + 1];
      }
      else{
        ans[i] = max(zero, ans[i + 1] - one * two);
      }
      tree.merge(data[i][0], data[i][1]);
    }
    for (int i = 1; i < M + 1; i++) {
      cout << ans[i] << endl;
    }
  
    return 0;
}
