#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <math.h>
#include <cassert>
#define rep(i,n) for(int i = 0; i < n; ++i )
using namespace std;
using ll = long long;
using P = pair<int,int>;

struct UnionFind {
  vector<int> parent,s;
  UnionFind(int n): parent(n), s(n){
    rep(i,n) {
      parent[i] = i;
      s[i] = 1;
    }
  }
  int root(int x) { return parent[x]==x ? x : parent[x] = root(parent[x]); }
  bool same(int x, int y) { return root(x)==root(y); }
  int size(int x){ return s[root(x)]; }
  void unite(int x, int y) {
    x = root(x); y = root(y);
    if (x == y) return;
    if (s[x] < s[y]) {
      parent[x] = y;
      s[y] += s[x];
    } else {
      parent[y] = x;
      s[x] += s[y];
    }   
  }
};

int main() {
  int n,m;
  cin >> n >> m;
  vector<P> e(m);
  rep(i,m) cin >> e[i].first >> e[i].second;
  
  UnionFind u(n);
  vector<ll> d(m,0LL);
  rep(i,m){
    int a = e[m-1-i].first, b = e[m-1-i].second;
    --a; --b;
    if(u.same(a,b)) continue;
    d[m-1-i] = u.size(a)*u.size(b);
    u.unite(a,b);
  }
  ll ans = 0;
  rep(i,m){
    ans += d[i];
    cout << ans << endl;
  }
}