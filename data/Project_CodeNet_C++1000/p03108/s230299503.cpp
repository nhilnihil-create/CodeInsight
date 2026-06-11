#include <bits/stdc++.h>

#include <iostream>
//#include <algorithm>
// #include <iomanip>
#define ll long long
// #define map unordered_map
// #define set unordered_set
#define pll pair<ll, ll>
#define vll vector<ll>

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

ll N, M;

ll calc(UnionFind uf) {
  map<ll, ll> m;
  for (ll i = 1; i <= N; i++) {
    m[uf.find(i)]++;
  }

  ll r = 0;
  auto ite = m.begin();
  for (; ite != end(m); ite++) {
    ll count = (*ite).second;
    cout << (*ite).first << "," << count << endl;
  }

  return r;
}

int main() {
  scanf("%lld %lld", &N, &M);

  UnionFind uf = UnionFind(N + 1);

  vector<pair<ll, ll>> list(M);
  for (ll i = 0; i < M; i++) {
    ll a, b;
    scanf("%lld %lld", &a, &b);
    list[i] = make_pair(a, b);
  }

  reverse(list.begin(), list.end());

  vll ans;

  ll val = N * (N - 1) / 2;
  ans.emplace_back(val);
  for (ll i = 0; i < M; i++) {
    if (i == M - 1) {
      break;
    }
    ll a = list[i].first;
    ll b = list[i].second;

    bool same = uf.same(a, b);

    ll a_size = uf.size(a);
    ll b_size = uf.size(b);

    uf.unite(a, b);

    if (!same) {
      bool same2 = uf.same(a, b);
      if (same2) {
        val -= (a_size * b_size);
      }
    }
    ans.emplace_back(val);
  }

  reverse(ans.begin(), ans.end());

  for (ll i = 0; i < M; i++) {
    cout << ans[i] << endl;
  }
}

// 0
// 0
// 4
// 5
// 6
