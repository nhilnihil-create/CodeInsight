#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  int n;
  cin >> n;
  
  double sumt = 0;
  vector<double> t(n), v(n);
  for (int i = 0; i < n; i++) {
    cin >> t.at(i);
    sumt += t.at(i);
  }
  for (int i = 0; i < n; i++) cin >> v.at(i);
  
  vector<double> x(sumt * 2 + 1, 1e9);
  
  int m = sumt * 2;
  for (double i = 0; i <= m; i++) x.at(i) = min(x.at(i), i / 2);
  for (double i = 0; i <= m; i++) x.at(m - i) = min(x.at(m - i), i / 2);
  double now = 0;
  for (int i = 0; i < n; i++) {
    for (double j = now; j <= now + 2 * t.at(i); j++) {
      x.at(j) = min(x.at(j), v.at(i));
    }
    for (double j = 0; j <= now; j++) {
      x.at(now - j) = min(x.at(now - j), v.at(i) + j / 2);
    }
    now += t.at(i) * 2;
    for (double j = 0; j <= m - now; j++) {
      x.at(now + j) = min(x.at(now + j), v.at(i) + j / 2);
    }
  }
  
  double ans = 0;
  for (int i = 1; i <= m; i++) {
    ans += (x.at(i - 1) + x.at(i)) / 4;
  }
  
  cout << fixed << setprecision(10) << ans << '\n';
}