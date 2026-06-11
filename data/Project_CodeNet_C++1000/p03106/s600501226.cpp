#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"

void solve() {
  ll a, b, k, ans = 1;
  cin >> a >> b >> k;
  ans = __gcd(a, b);
  ll z = ans;
  for (ll i = z; i >= 1; --i) {
    if (a % i == 0 && b % i == 0) {
      ans = i;
      --k;
    }
    if (!k)
      break;
  }
  cout << ans << endl;
}

int main() {
  ll t;
  // cin >> t;
  t = 1;
  while (t--)
    solve();
  return 0;
}