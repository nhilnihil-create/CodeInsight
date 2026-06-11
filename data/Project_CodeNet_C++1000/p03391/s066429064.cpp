#include <bits/stdc++.h>
using namespace std;
inline void chmin (int& a, int b) {
  if (a > b) a = b;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
  }
  long long sum = 0;
  int minv = 1e9 + 1;
  for (int i = 0; i < n; i++) {
    sum += a[i];
    if (a[i] > b[i]) {
      chmin(minv, b[i]);
    }
  }
  if (minv == 1e9 + 1) {
    cout << 0 << '\n';
  } else {
    cout << sum - minv << '\n';
  }
  return 0;
}