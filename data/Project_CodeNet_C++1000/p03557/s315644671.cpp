#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> b(n);
  vector<int> c(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  for (int i = 0; i < n; ++i) cin >> b[i];
  for (int i = 0; i < n; ++i) cin >> c[i];
  sort(a.begin(), a.end());
  sort(c.begin(), c.end());

  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    int k = b[i];
    int aidx = lower_bound(a.begin(), a.end(), k) - a.begin() - 1;
    int cidx = upper_bound(c.begin(), c.end(), k) - c.begin();
    ans += (long long)(aidx + 1) * (n - cidx);
  }
  cout << ans << '\n';
  return 0;
}
