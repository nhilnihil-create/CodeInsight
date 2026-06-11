#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<long long> cs(n), sum(n), ms(n);
  for (int i = 0; i < n; i++) {
    if (s[i] == 'M') ms[i]++;
    if (s[i] == 'C') cs[i]++;
  }
  for (int i = 1; i < n; i++) {
    ms[i] += ms[i - 1];
    cs[i] += cs[i - 1];
  }
  for (int i = 0; i < n; i++) {
    if (s[i] == 'C') sum[i] += ms[i];
  }
  for (int i = 1; i < n; i++) {
    sum[i] += sum[i - 1];
  }
  int q;
  cin >> q;
  for (int u = 0; u < q; u++) {
    int k;
    cin >> k;
    long long ans = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == 'D') {
        int r = min(n - 1, i + k - 1);
        ans += sum[r] - sum[i] - ms[i] * (cs[r] - cs[i]);
      }
    }
    cout << ans << '\n';
  }
  return 0;
}