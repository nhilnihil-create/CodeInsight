#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;

int main() {
  int n;
  cin >> n;
  vector<i64> a(n), b(n);
  for (i64& x : a) cin >> x;
  for (i64& x : b) cin >> x;
  i64 sa = accumulate(a.begin(), a.end(), 0ll);
  i64 sb = accumulate(b.begin(), b.end(), 0ll);
  i64 ma = sb - sa;
  i64 m1 = 0, m2 = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] > b[i])
      m1 += a[i] - b[i];
    else
      m2 += (b[i] - a[i] + 1) / 2;
  }
  cout << ((ma >= m1 && ma >= m2) ? "Yes" : "No") << '\n';
}