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

void solve(ll N, std::string s) {
  vector<vector<ll>> dp(N, vector<ll>(N, 0));
  rep(i, N) dp.at(0).at(i) = 1;
  vector<ll> cum(N + 2, 0);

  rep(i, N - 1) {
    FOR(j, 1, N + 1) cum.at(j) = (cum.at(j - 1) + dp.at(i).at(j - 1)) % MOD;

    rep(j, N - i) {
      if (s.at(i) == '<') {
        dp.at(i + 1).at(j) = (cum.at(N - i) - cum.at(j + 1) + MOD) % MOD;
      } else {
        dp.at(i + 1).at(j) = cum.at(j + 1) % MOD;
      }
    }
  }

  cout << dp.at(N - 1).at(0) << endl;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(15);
  ll N;
  cin >> N;
  std::string s;
  std::cin >> s;
  solve(N, s);
  return 0;
}
