#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> v(n);
  for (int i = 0; i < n; ++i) cin >> v[i];

  int ans = INT_MIN;
  for (int l = 0; l <= n; ++l) {
    for (int r = 0; l + r <= n; ++r) {
      if (l + r > k) continue;

      vector<int> w;
      for (int i = 0; i < l; ++i) w.push_back(v[i]);
      for (int i = 0; i < r; ++i) w.push_back(v[n - 1 - i]);

      int sum = accumulate(w.begin(), w.end(), 0);
      sort(w.begin(), w.end());
      for (int i = 0; i < min(k - l - r, (int)w.size()); ++i)
        sum -= min(0, w[i]);
      ans = max(ans, sum);
    }
  }
  cout << ans << endl;
  return 0;
}
