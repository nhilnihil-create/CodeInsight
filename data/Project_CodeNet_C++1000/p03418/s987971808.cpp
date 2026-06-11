#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll n, k;
  cin >> n >> k;
  ll ans = 0;
  if (k == 0) {
    cout << n * n << endl;
    return 0;
  }
  for (int b = k + 1; b <= n; b++) {
    ans += n / b * (b - k) + max(0LL, n % b - k + 1);
  }
  cout << ans << endl;
}
