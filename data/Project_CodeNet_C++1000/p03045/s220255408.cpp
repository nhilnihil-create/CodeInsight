#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stdio.h>
#include<cstring>
#include<math.h>
#include<map>
#include<bitset>
#include<iomanip>
#include<queue>
#include<functional>
#include<stack>
#include<tuple>
#include<cassert>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
using ll = long long;
using P = pair<int, int>;
using MATRIX = vector< vector<ll> >;
template <class T> inline bool chmin(T &x, const T &y) {if (x > y) {x = y; return 1;} return 0;}
template <class T> inline bool chmax(T &x, const T &y) {if (x < y) {x = y; return 1;} return 0;}

struct UnionFind {
  vector<int> size, par;
  UnionFind(int n) {
    size.resize(n, 0);
    par.resize(n, 0);
    for(int i = 0; i < n; i++) {
      maketree(i);
    }
  }

  void maketree(int x) {
    par[x] = x;
    size[x] = 1;
  }

  int root(int x) {
    if(par[x] == x) return x;
    return par[x] = root(par[x]);
  }

  void unite(int x, int y) {
    int rx = root(x);
    int ry = root(y);
    if(rx == ry) return;
    if(size[rx] < size[ry]) par[rx] = ry;
    else {
      par[ry] = rx;
      if(size[rx] == size[ry]) size[rx]++;
    }
  }

  bool same(int x, int y) {
    int rx = root(x);
    int ry = root(y);
    return rx == ry;
  }
};

int main() {
  int N, M;
  cin >> N >> M;
  UnionFind tree(N);
  rep(i, M) {
    int x, y, z;
    cin >> x >> y >> z;
    x--;y--;
    tree.unite(x, y);
  }
  int ans = 0;
  rep(i, N) {
    if(tree.root(i) == i) {
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}