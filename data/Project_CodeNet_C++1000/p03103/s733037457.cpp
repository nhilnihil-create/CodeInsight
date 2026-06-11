#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
  ll n, m;
  cin >> n >> m;
  vector<pair<ll, ll>> d(n);
  for (int i = 0; i < n; i++) {
    cin >> d[i].first >> d[i].second;
  }
  sort(all(d));
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    if (d[i].second >= m) {
      ans += d[i].first * m;
      break;
    }
    ans += d[i].first * d[i].second;
    m -= d[i].second;
  }
  cout << ans << endl;
  return 0;
}