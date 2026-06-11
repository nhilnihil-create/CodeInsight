/**
 *    author:  tourist
 *    created: 29.12.2019 23:04:52       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int> b(n);
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  int an = 0;
  for (int bit = 0; bit < 30; bit++) {
    vector<int> c(n);
    for (int i = 0; i < n; i++) c[i] = (a[i] % (1 << (bit + 1)));
    vector<int> d(n);
    for (int i = 0; i < n; i++) d[i] = (b[i] % (1 << (bit + 1)));
    sort(c.begin(), c.end());
    sort(d.begin(), d.end());
    long long ans = 0;
    int j = n;
    for (int i = 0; i < n; i++) {
      while (j > 0 && c[i] + d[j - 1] >= (1 << bit)) --j;
      ans += n - j;
    }
    j = n;
    for (int i = 0; i < n; i++) {
      while (j > 0 && c[i] + d[j - 1] >= 2 * (1 << bit)) --j;
      ans -= n - j;
    }
    j = n;
    for (int i = 0; i < n; i++) {
      while (j > 0 && c[i] + d[j - 1] >= 3 * (1 << bit)) --j;
      ans += n - j;
    }
    if (ans % 2) an ^= (1 << bit);
  }
  cout << an << '\n';
  return 0;
}
