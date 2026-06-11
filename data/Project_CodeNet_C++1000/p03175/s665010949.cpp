#include <bits/stdc++.h>

#define CHOOSE(a) CHOOSE2 a
#define CHOOSE2(a0, a1, a2, a3, a4, x, ...) x
#define dump_1(x1) cerr << #x1 << ": " << x1 << endl
#define dump_2(x1, x2) \
  cerr << #x1 << ": " << x1 << ", " #x2 << ": " << x2 << endl
#define dump_3(x1, x2, x3)                                                \
  cerr << #x1 << ": " << x1 << ", " #x2 << ": " << x2 << ", " #x3 << ": " \
       << x3 << endl
#define dump_4(x1, x2, x3, x4)                                            \
  cerr << #x1 << ": " << x1 << ", " #x2 << ": " << x2 << ", " #x3 << ": " \
       << x3 << ", " #x4 << ": " << x4 << endl
#define dump_5(x1, x2, x3, x4, x5)                                        \
  cerr << #x1 << ": " << x1 << ", " #x2 << ": " << x2 << ", " #x3 << ": " \
       << x3 << ", " #x4 << ": " << x4 << ", " #x5 << ": " << x5 << endl
#define dump(...) \
  CHOOSE((__VA_ARGS__, dump_5, dump_4, dump_3, dump_2, dump_1, ~))(__VA_ARGS__)
#define check(s) cerr << s << endl

#define rep(i, n) for (int i = 0; i < n; i++)
#define repr(i, n) for (int i = n; i >= 0; i--)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define unique(v) v.erase(unique(v.begin(), v.end()), v.end());
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)

using namespace std;

using ll = long long;

const long long MOD = 1000000007;

vector<int> dx = {0, 1, 0, -1};
vector<int> dy = {1, 0, -1, 0};

const ll LINF = 2e18;
const int INF = 1e9;

ll N;
vector<ll> x, y;

vector<vector<ll>> dp;
vector<bool> seen;
vector<vector<ll>> G;

void f(ll i, ll p) {
  if (seen.at(i)) return;
  seen.at(i) = true;
  dp.at(i).at(0) = 1;
  dp.at(i).at(1) = 1;
  for (ll j : G.at(i)) {
    if (j == p) continue;
    f(j, i);
    dp.at(i).at(0) = dp.at(i).at(0) * (dp.at(j).at(0) + dp.at(j).at(1)) % MOD;
    dp.at(i).at(1) = dp.at(i).at(1) * dp.at(j).at(0) % MOD;
  }
  return;
}

void solve() {
  seen.resize(N, false);
  dp.resize(N, vector<ll>(2));
  G.resize(N);

  rep(i, N - 1) {
    G.at(x.at(i)).push_back(y.at(i));
    G.at(y.at(i)).push_back(x.at(i));
  }

  f(0, -1);
  ll ans = (dp.at(0).at(0) + dp.at(0).at(1)) % MOD;
  cout << ans << endl;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(15);
  scanf("%lld", &N);
  x.resize(N - 1);
  y.resize(N - 1);
  for (int i = 0; i < N - 1; i++) {
    scanf("%lld %lld", &x.at(i), &y.at(i));
    x.at(i)--;
    y.at(i)--;
  }
  solve();
  return 0;
}
