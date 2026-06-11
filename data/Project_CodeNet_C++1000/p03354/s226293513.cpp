#include <bits/stdc++.h>
using namespace std;
using ll = long long;

class UnionFind {
private:
  vector<int> par;
public:
  UnionFind(int N) {
    par.resize(N);
    for (int i = 0; i < N; i++) par[i] = i;
  }
  int root(int x) { return (x == par[x])? x: (par[x] = root(par[x])); }
  void unite(int x, int y) { par[root(y)] = root(x); }
  bool same(int x, int y) { return (root(x) == root(y)); }
};

int main() {
  int N, M;
  cin >> N >> M;
  UnionFind UF(N);

  vector<ll> P(N); for (ll i = 0; i < N; i++) cin >> P[i];

  for (int i = 0; i < M; i++) {
    int x, y;
    cin >> x >> y; x--; y--;
    UF.unite(x, y);
  }

  ll ans = 0;
  for (ll i = 0; i < N; i++) {
    ll p = P[i] - 1;
    if (UF.same(i, p)) ans++;
  }
  cout << ans << '\n';

  return 0;
}