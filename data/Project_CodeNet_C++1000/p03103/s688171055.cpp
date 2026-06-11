#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <iomanip>
#include <set>
#include <sstream>
#include <queue>
using namespace std;
typedef long long ll;

int main() {
  ll n, m;
  cin >> n >> m;

  vector<pair<ll, ll>> v;
  for (ll i = 0; i < n; i++) {
    ll a, b;
    cin >> a >> b;
    v.push_back({a, b});
  }

  sort(v.begin(), v.end());

  ll ans = 0;
  ll current = m;
  for (auto x : v) {
    if (current - x.second >= 0) {
      ans += x.first * x.second;
      current -= x.second;
    } else {
      ans += x.first * current;
      cout << ans << endl;
      return 0;
    }
  }
  cout << ans << endl;
  return 0;
}