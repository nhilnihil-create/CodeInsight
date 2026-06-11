#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<ll, ll>;

ll n, m, ans;

int main() {
  cin >> n >> m;
  vector<P> drink(n);
  rep (i, n) {
    cin >> drink[i].first >> drink[i].second;
  }
  sort(drink.begin(), drink.end());
  ans = 0;
  rep (i, n) {
    if (m <= drink[i].second) {
      ans += m * drink[i].first;
      break;
    } else {
      ans += drink[i].second * drink[i].first;
      m -= drink[i].second;
    }
  }
  cout << ans << endl;
  return 0;
}
