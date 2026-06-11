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

#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using ll = long long;
using P = pair<long long, long long>;
using MATRIX = vector< vector<ll> >;
template <class T> inline bool chmin(T &x, const T &y) {if (x > y) {x = y; return 1;} return 0;}
template <class T> inline bool chmax(T &x, const T &y) {if (x < y) {x = y; return 1;} return 0;}

struct UnionFind {
  vector<long long> size, par;
  UnionFind(long long n) {
    size.resize(n, 0);
    par.resize(n, 0);
    for(long long i = 0; i < n; i++) {
      maketree(i);
    }
  }

  void maketree(long long x) {
    par[x] = x;
    size[x] = 1;
  }

  long long root(long long x) {
    if(par[x] == x) return x;
    return par[x] = root(par[x]);
  }

  void unite(long long x, long long y) {
    long long rx = root(x);
    long long ry = root(y);
    if(rx == ry) return;
    if(size[rx] < size[ry]) par[rx] = ry;
    else {
      par[ry] = rx;
      if(size[rx] == size[ry]) size[rx]++;
    }
  }

  bool same(long long x, long long y) {
    long long rx = root(x);
    long long ry = root(y);
    return rx == ry;
  }
};

int main() {
  long long N, M;
  cin >> N >> M;
  UnionFind tree(2 * N);
  rep(i, M) {
    long long a, b;
    cin >> a >> b;
    a--;b--;
    tree.unite(a, b + N);
    tree.unite(a + N, b);
  }
  bool f = false;
  long long cnt = 0;
  rep(i, N) {
    if(tree.same(i, i + N)) {
      cout << N * (N - 1) / 2 - M << endl;
      return 0;
    }
  }
  rep(i, N) {
    if(tree.same(0, i)) {
      cnt++;
    }
  }
  cout << cnt * (N - cnt) - M << endl;
  return 0;
}