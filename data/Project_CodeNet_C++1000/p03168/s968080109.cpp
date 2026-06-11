/**
 *    author:  math2do
 *    created: 04.09.2020 13:08:32
**/

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector <double> p(n);
  for (int i = 0; i < n; i++) {
    cin >> p[i];
  } 
  vector <double> dp(n + 1);
  dp[0] = 1;
  for (int c = 0; c < n; c++) {
    double h = p[c];
    for (int i = c + 1; i >= 0; i--) {
      dp[i] = (i == 0 ? 0 : dp[i - 1] * h) + dp[i] * (1 - h);
    } 
  } 
  double ans = 0.0;
  for (int h = 0; h <= n; h++) {
    int t = n - h;
    if (h > t) {
      ans += dp[h];
    } 
  } 
  cout << fixed << setprecision(17) << ans << endl;
  return 0;
}
