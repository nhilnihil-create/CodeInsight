#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main() {
  ll n, ans = 0;
  cin >> n;
  for (ll i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      ll m = n / i - 1;
      if (m != 0 && n / m == n % m) ans += m;
    }
  }
  cout << ans << endl;
  return 0;
}