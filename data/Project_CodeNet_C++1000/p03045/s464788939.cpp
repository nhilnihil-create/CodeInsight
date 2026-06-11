#include <bits/stdc++.h>

#include <iostream>
//#include <algorithm>
// #include <iomanip>
#define ll long long
#define map unordered_map
#define set unordered_set
#define l_l pair<ll, ll>
#define vll vector<ll>
#define mll map<ll, ll>

using namespace std;

const ll MOD = 1000000007LL;
const ll INF = (1LL << 60LL);

struct UnionFind {
  vector<ll> data;

  UnionFind(ll sz) { data.assign(sz, -1); }

  bool unite(ll x, ll y) {
    x = find(x), y = find(y);
    if (x == y) return (false);
    if (data[x] > data[y]) swap(x, y);
    data[x] += data[y];
    data[y] = x;
    return (true);
  }

  ll find(ll k) {
    if (data[k] < 0) return (k);
    return (data[k] = find(data[k]));
  }

  ll size(ll k) { return (-data[find(k)]); }

  bool same(ll x, ll y) {
    int rx = find(x);
    int ry = find(y);
    return rx == ry;
  }
};

int main() {
  auto uf = UnionFind(100005);
  ll N, M;
  scanf("%lld %lld", &N, &M);

  for (ll i = 0; i < M; i++) {
    ll x, y, z;
    scanf("%lld %lld %lld", &x, &y, &z);

    uf.unite(x, y);
  }

  ll ans = 0;

  mll m;

  for (ll i = 1; i <= N; i++) {
    ll root = uf.find(i);
    if (m[root]) {
      continue;
    }

    // ans += uf.size(i) - 1;
    ans++;

    m[root] = 1;
  }

  cout << (ans) << endl;
}
