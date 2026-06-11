#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
typedef long long ll;

ll n;

void solve() {
  // N = mx + y where y < m
  // N mod m = y, [N / m] = x thus N = (m + 1)y where y < m
  vector<ll> v;
  for (ll i = 1;i<sqrt(n);i++) {
    if (n % i == 0 && n / i - 1 > i) {
      v.push_back(n / i - 1);
    }
  }
  ll ans = 0;
  for (int i=0;i<v.size();i++) {
    ans += v[i];
  }
  cout << ans << endl;
}

int main() {
  cin >> n;
  solve();
}
