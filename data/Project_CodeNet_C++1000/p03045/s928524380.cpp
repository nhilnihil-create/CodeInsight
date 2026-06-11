#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
using ll = long long;
using P = pair<int, int>;
ll GCD(ll a, ll b) { return b?GCD(b, a%b):a; }
ll LCM(ll a, ll b) { return a/GCD(a, b)*b; }

// UnionFind
struct UnionFind {
  vector<int> d;
  UnionFind(int n=0): d(n,-1) {}

  // ある要素がどの集合に属しているかを返す
  int find(int x) {
    if (d[x] < 0) return x;
    return d[x] = find(d[x]);
  }

  // 集合をマージする、すでに同じ集合ならfalseが返る
  bool unite(int x, int y) {
    x = find(x); y = find(y);
    if (x == y) return false;
    if (d[x] > d[y]) swap(x,y);
    d[x] += d[y];
    d[y] = x;
    return true;
  }

  // 2つの要素が同じ集合か判定する
  bool same(int x, int y) { return find(x) == find(y);}
  
  // ある集合の大きさあを答える
  int size(int x) { return -d[find(x)];}
};

int main() {
    int n, m;
    cin >> n >> m;
    UnionFind tree(n);
    vector<bool> A(n, false);
    vector<bool> AA(n, false);
    for(int i = 0; i < m; ++i) {
        int xx, yy, zz;
        cin >> xx >> yy >> zz;
        xx--; yy--;
        tree.unite(xx, yy);
        A.at(xx) = true; A.at(yy) = true;
    }

    int cnt = 0;
    for(int i = 0; i < n; ++i) {
        if(!A.at(i)) {
            cnt++;
            AA.at(i) = true;
        }
        if(!AA.at(tree.find(i))) {
            cnt++;
            int check = tree.find(i);
            AA.at(check) = true;
        }
    }
    cout << cnt << endl;
}