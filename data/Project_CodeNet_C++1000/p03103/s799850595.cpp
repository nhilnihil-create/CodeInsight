#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {
  int n, m;
  cin >> n >> m;
  vector<pair<ll, ll>> v(n);
  rep(i, n) cin >> v[i].first >> v[i].second;
  sort(v.begin(), v.end());
  ll ans = 0;
  rep(i, n) {
    if (m > v[i].second) {
      ans += v[i].first * v[i].second;
      m -= v[i].second;
    }
    else {
      ans += v[i].first * m;
      break;
    }
  }
  cout << ans << endl;
  return 0;
}
