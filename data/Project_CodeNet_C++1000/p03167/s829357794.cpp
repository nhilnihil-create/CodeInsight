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

void solve(ll H, ll W, std::vector<std::vector<char>> a) {
  vector<vector<ll>> dp(H + 1, vector<ll>(W + 1, 0));
  dp.at(1).at(1) = 1;
  rep(i, H) {
    rep(j, W) {
      if (a.at(i).at(j) == '#') {
        dp.at(i + 1).at(j + 1) = 0;
        continue;
      }
      chmax(dp.at(i + 1).at(j + 1),
            (dp.at(i + 1).at(j) + dp.at(i).at(j + 1)) % MOD);
    }
  }

  cout << dp.at(H).at(W) << endl;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(15);
  ll H, W;
  cin >> H;
  cin >> W;
  std::vector<std::vector<char>> a(H, vector<char>(W));
  for (int i = 0; i < H; i++) {
    string s;
    std::cin >> s;
    for (int j = 0; j < W; j++) a.at(i).at(j) = s.at(j);
  }
  solve(H, W, std::move(a));
  return 0;
}
