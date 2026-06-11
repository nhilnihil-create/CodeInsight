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

void disp(ll N, ll K, vector<vector<ll>> dp) {
  rep(i, N + 1) {
    rep(j, K + 1) { cerr << dp.at(i).at(j) << " "; }
    cerr << endl;
  }
  cerr << endl;
}

void solve(ll N, ll K, std::vector<ll> a) {
  vector<vector<ll>> dp(N + 1, vector<ll>(K + 1, 0));
  dp.at(0).at(0) = 1;
  vector<ll> acc(K + 2, 0);

  rep(i, N) {
    acc.at(0) = 0;
    rep(k, K + 1) acc.at(k + 1) = (acc.at(k) + dp.at(i).at(k)) % MOD;
    rep(j, K + 1) {
      dp.at(i + 1).at(j) =
          (acc.at(j + 1) - acc.at(max(0LL, j - a.at(i))) + MOD) % MOD;
    }
  }

  cout << dp.at(N).at(K) << endl;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(15);
  ll N;
  scanf("%lld", &N);
  ll K;
  scanf("%lld", &K);
  std::vector<ll> a(N);
  for (int i = 0; i < N; i++) {
    scanf("%lld", &a[i]);
  }
  solve(N, K, std::move(a));
  return 0;
}
