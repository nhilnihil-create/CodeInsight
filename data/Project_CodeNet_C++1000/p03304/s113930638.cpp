#include <bits/stdc++.h>

#define rep(i, n) for (ll i = 0; i < (n); i++)
#define rep2(i, a, b) for (ll i = (a); i < (b); i++)
typedef uint64_t ull;
typedef int64_t ll;
typedef std::pair<ll, ll> PLL;

using namespace std;

ll N, M, d;

signed main() {
  cin >> N >> M >> d;

  ll p = 0;
  if (d == 0) {
    p += N;
  } else {
    p += (N-d); // 増加する側
    p += (N-d); // 減少する側
  }
  double ans = (1.0 * p / (N*N)) * (M-1);
  printf("%.10f\n", ans);
}
