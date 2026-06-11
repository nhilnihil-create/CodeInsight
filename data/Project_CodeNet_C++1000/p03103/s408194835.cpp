
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
using ll = long long;
using P = pair<int, int>;

int main() {
  ll n, m;
  cin >> n >> m;
  vector<pair<ll, ll>> drink(n);
  rep(i,n) {
    ll a, b;
    cin >> a >> b;
    drink[i] = make_pair(a, b);
  }
  sort(drink.begin(), drink.end());

  ll ans = 0;
  rep(i,n) {
    if (m >= drink[i].second) {
      m -= drink[i].second;
      ans += drink[i].first*drink[i].second;
    } else {
      ans += drink[i].first*m;
      m = 0;
    }
    if (m == 0) break;
  }
  cout << ans << endl;
  return 0;
}