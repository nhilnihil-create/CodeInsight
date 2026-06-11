#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n)                    \
  for (int i = 0; i < (int)(n); i++) \
    ;

#define _GLIBCXX_DEBUG
#define _LIBCPP_DEBUG 0

vector<ll> h;

const ll INF = 1000000000000000000 + 7;

ll cost(ll i, ll j) { return abs(h.at(i) - h.at(j)); }

int main() {
  ll n, k;
  cin >> n >> k;
  h.resize(n);

  for (auto &x : h) {
    cin >> x;
  }

  vector<ll> dp(n, INF);
  dp.at(0) = 0;

  for (long long i = 0; i < n; i++) {
    for (long long j = 1; j <= k && i + j < n; j++) {
      dp.at(i + j) = min(dp.at(i + j), dp.at(i) + cost(i, i + j));
    }
  }

  cout << dp.at(n - 1) << endl;
}
