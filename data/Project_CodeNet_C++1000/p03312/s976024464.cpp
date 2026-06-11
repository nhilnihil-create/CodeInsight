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

template <typename T>
std::ostream& operator<<(std::ostream& os, std::vector<T>& a) {
  for (int i = 0; i < (int)a.size(); ++i)
    os << a[i] << " \n"[i == (int)a.size() - 1];
  return os;
}

constexpr ll MOD = 1000000007;
constexpr int INF = 0x3f3f3f3f;
constexpr ll INFL = 0x3f3f3f3f3f3f3f3fLL;

int main() {
  ll n;
  cin >> n;
  vector<ll> a(n), s(n + 1);
  rep(i, 0, n) {
    cin >> a[i];
    s[i + 1] = s[i] + a[i];
  }

  ll ans = INFL;
  // [l, r)
  int l = 1;
  int r = 3;
  rep(center, 2, n - 1) {
    ll pq = s[center];
    ll rs = s[n] - s[center];

    // lとrを動かす
    while (l + 1 < center &&
           abs((pq - s[l]) - s[l]) > abs((pq - s[l + 1]) - s[l + 1]))
      ++l;
    while (r + 1 < n && abs((s[r] - s[center]) - (s[n] - s[r])) >
                          abs((s[r + 1] - s[center]) - (s[n] - s[r + 1])))
      ++r;

    ll P = pq - s[l];
    ll Q = s[l];
    ll R = s[r] - s[center];
    ll S = rs - R;
    // cout << Q << " " << P << " " << R << " " << S << endl;
    ll v = max(P, max(Q, max(R, S))) - min(P, min(Q, min(R, S)));
    ans = min(ans, v);
  }
  cout << ans << endl;
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
  return 0;
}