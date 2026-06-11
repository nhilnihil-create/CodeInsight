#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;
using ll = int64_t;
#define rep(i, j, n) for (int i = j; i < (int)n; ++i)
#define rrep(i, j, n) for (int i = (int)n - 1; j <= i; --i)

constexpr ll MOD = 1000000007;
constexpr int INF = 0x3f3f3f3f;
constexpr ll INFL = 0x3f3f3f3f3f3f3f3fLL;

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }

int main() {
  int n, m;
  cin >> n >> m;
  string s, t;
  cin >> s >> t;
  // s - 1,
  ll g = gcd(n, m);
  ll l = n / g * m;

  // s の a文字目 == tのb文字目
  // それ以上の値はあるか？

  bool ok = true;
  rep(i, 0, g) if (s[n / g * i] != t[m / g * i]) ok = false;

  if (ok)
    cout << l;
  else
    cout << -1;
  cout << endl;

#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
  return 0;
}