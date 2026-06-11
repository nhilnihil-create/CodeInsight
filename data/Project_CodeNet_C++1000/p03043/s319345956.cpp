#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;
using ll = long long;

int main() {
  ll n, k;
  cin >> n >> k;
  vector<int> twos(19);
  twos[0] = 1;
  rep(i, 18) { twos[i + 1] = twos[i] * 2; }
  double ans = 0.0;
  if (k <= n) {
    ans += (double)(n - k + 1) / (double)n;
  }
  int m = k - 1 <= n ? k - 1 : n;
  for (int i = 1; i <= m; i++) {
    rep(j, 19) {
      if (k <= i * twos[j]) {
        ans += 1.0 / (double)twos[j] / (double)n;
        break;
      }
    }
  }
  cout << fixed << setprecision(9) << ans << endl;
  return 0;
}
