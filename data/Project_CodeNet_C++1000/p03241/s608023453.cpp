#include <bits/stdc++.h>

#define rep(i, n) for (ll i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
const int INF = 1e9;

int main() {
  ll n, m;
  cin >> n >> m;

  ll ans = 1;

  vector<ll> res;
  for (ll i = 1; i * i <= m; ++i) {
    if (m % i == 0) {
      res.push_back(i);
      res.push_back(m / i);
    }
  }

  for (auto a : res)
    if (a * n <= m) ans = max(ans, a);

  cout << ans << endl;
  return 0;
}
