#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n)                    \
  for (int i = 0; i < (int)(n); i++) \
    ;

#define _GLIBCXX_DEBUG
#define _LIBCPP_DEBUG 0

const ll INF = 1000000000000000000 + 7;

vector<ll> h;

ll cost(ll i, ll j) { return abs(h.at(i) - h.at(j)); }

int main() {
  long long n;
  cin >> n;

  h.resize(n);
  for (long long i = 0; i < n; i++) {
    cin >> h.at(i);
  }

  vector<ll> dp(n, INF);

  dp.at(0) = 0;
  dp.at(1) = cost(0, 1);

  // 貰うDP
  /* for (long long i = 2; i < n; i++) { */
  /*   dp.at(i) = */
  /*       min(dp.at(i - 1) + cost(i, i - 1), dp.at(i - 2) + cost(i, i - 2)); */
  /* } */

  // 配るDP
  for (long long i = 0; i < n - 1; i++) {
    dp.at(i + 1) = min(dp.at(i + 1), dp.at(i) + cost(i, i + 1));
    if (i + 2 < n) {
      dp.at(i + 2) = min(dp.at(i + 2), dp.at(i) + cost(i, i + 2));
    }
  }

  cout << dp.at(n - 1) << endl;
}
