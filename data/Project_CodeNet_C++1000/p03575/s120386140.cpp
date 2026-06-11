#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define CHOOSE(a) CHOOSE2 a
#define CHOOSE2(a0, a1, a2, a3, a4, x, ...) x
#define debug_1(x1) cerr << #x1 << ": " << x1 << endl
#define debug_2(x1, x2) \
  cerr << #x1 << ": " << x1 << ", " #x2 << ": " << x2 << endl
#define debug_3(x1, x2, x3)                                               \
  cerr << #x1 << ": " << x1 << ", " #x2 << ": " << x2 << ", " #x3 << ": " \
       << x3 << endl
#define debug_4(x1, x2, x3, x4)                                           \
  cerr << #x1 << ": " << x1 << ", " #x2 << ": " << x2 << ", " #x3 << ": " \
       << x3 << ", " #x4 << ": " << x4 << endl
#define debug_5(x1, x2, x3, x4, x5)                                       \
  cerr << #x1 << ": " << x1 << ", " #x2 << ": " << x2 << ", " #x3 << ": " \
       << x3 << ", " #x4 << ": " << x4 << ", " #x5 << ": " << x5 << endl
#define debug(...)                                                      \
  CHOOSE((__VA_ARGS__, debug_5, debug_4, debug_3, debug_2, debug_1, ~)) \
  (__VA_ARGS__)
#define check(s) cerr << s << endl

#define rep(i, n) for (int i = 0; i < n; i++)
#define repr(i, n) for (int i = n; i >= 0; i--)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define unique(v) v.erase(unique(v.begin(), v.end()), v.end());

vector<int> dx = {0, 1, 0, -1};
vector<int> dy = {1, 0, -1, 0};

const ll LINF = 2e18;
const int INF = 1e9;

// UnionFind
// coding: https://youtu.be/TdR816rqc3s?t=726
// comment: https://youtu.be/TdR816rqc3s?t=6822
struct UnionFind {
  vector<int> d;
  UnionFind(int n = 0) : d(n, -1) {}
  int find(int x) {
    if (d[x] < 0) return x;
    return d[x] = find(d[x]);
  }
  bool unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return false;
    if (d[x] > d[y]) swap(x, y);
    d[x] += d[y];
    d[y] = x;
    return true;
  }
  bool same(int x, int y) { return find(x) == find(y); }
  int size(int x) { return -d[find(x)]; }
};

void solve(ll N, ll M, std::vector<ll> a, std::vector<ll> b) {
  ll ans = 0;
  rep(i, M) {
    UnionFind uf = UnionFind(N);
    rep(j, M) {
      if (i != j) uf.unite(a.at(j), b.at(j));
    }

    ll cnt = 0;
    rep(j, N) {
      if (uf.d.at(j) < 0) cnt++;
    }
    if (cnt >= 2) ans++;
  }

  cout << ans << endl;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(15);
  ll N;
  scanf("%lld", &N);
  ll M;
  scanf("%lld", &M);
  std::vector<ll> a(M);
  std::vector<ll> b(M);
  for (int i = 0; i < M; i++) {
    scanf("%lld", &a[i]);
    scanf("%lld", &b[i]);
    --a.at(i);
    --b.at(i);
  }
  solve(N, M, std::move(a), std::move(b));
  return 0;
}
