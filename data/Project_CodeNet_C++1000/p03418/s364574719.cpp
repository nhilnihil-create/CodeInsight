#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  ll n, k;
  cin >> n >> k;
  
  ll ans = 0;
  for (ll b = k + 1; b <= n; b++) {
    ans += (n / b) * (b - k);
    if (k == 0) ans += n % b;
    else if (n % b >= k) ans += (n % b) - (k - 1);
  }
  
  cout << ans << '\n';
}