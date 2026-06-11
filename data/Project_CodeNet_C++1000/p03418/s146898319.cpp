#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll MOD = 1000000007;
ll INFL = 1ll << 60;
ll INF = 1 << 28;

// ====================================================================

int main() {
  ll n, k;
  cin >> n >> k;
  ll ans = 0;
  for (int b = 1; b <= n; b++) {
    if (b <= k) continue;
    ans += n / b * (b - k) + max(0ll, n % b - k + (k > 0));
    // cout << b << " " << n / b * (b - k) << " " << max(0ll, n % b - k + (k > 0)) << endl;
  }
  cout << ans << endl;
}