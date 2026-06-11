#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  double ans = 0;
  for (int i = 1; i <= n; i++) {
    int score = i;
    double a = 1.;
    while (score < k) {
      score *= 2;
      a /= 2.;
    }
    ans += a / n;
  }
  cout << fixed << setprecision(17);
  cout << ans << '\n';
  return 0;
}
