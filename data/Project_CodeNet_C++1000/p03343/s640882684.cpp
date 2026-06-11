#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, k, q;
  cin >> n >> k >> q;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  int ans = (int) 1e9 + 1;
  for (int i = 0; i < n; i++) { /* lower bound */
    vector<int> interval, ok;
    for (int j = 0; j <= n; j++) {
      if (j != n && a[j] >= a[i]) {
        interval.emplace_back(a[j]);
      }
      else {
        if ((int)interval.size() >= k) {
          sort(interval.begin(), interval.end());
          for (int ii = 0; ii < (int) interval.size() - k + 1; ii++) {
            ok.emplace_back(interval[ii]);
          }
        }
        interval.clear();
      }
    }
    sort(ok.begin(), ok.end());
    if ((int) ok.size() >= q) {
      ans = min(ans, ok[q - 1] - a[i]);
    }
  }
  cout << ans << "\n";
  return 0;
}