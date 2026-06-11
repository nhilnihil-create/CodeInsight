#include <bits/stdc++.h>

using namespace std;

int main() {
  int n; cin >> n;

  vector<int> v(n);
  vector<long long> pref(n);
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
    pref[i] = v[i];
    if (i > 0)
      pref[i] += pref[i - 1];
  }

  int j = 0, k = 0;
  long long best = 2e18;
  for (int i = 1; i + 2 < n; ++i) {
    while (j + 1 < i && pref[j + 1] <= pref[i] / 2)
      ++j;
    while (k <= i || pref[k + 1] - pref[i] <= (pref[n - 1] - pref[i]) / 2)
      ++k;
    for (int jp = j; jp <= j + 1; ++jp)
      for (int kp = k; kp <= k + 1; ++kp) {
        if (jp < i && i < kp && kp < n) {
          long long minn = min({pref[jp], pref[i] - pref[jp], pref[kp] - pref[i], pref[n - 1] - pref[kp]});
          long long maxx = max({pref[jp], pref[i] - pref[jp], pref[kp] - pref[i], pref[n - 1] - pref[kp]});
          best = min(best, maxx - minn);
        }
      }
  }
  cout << best << endl;
}
