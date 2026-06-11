#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  int ans = 1;
  for (int i = 1; i * i <= m; ++i) {
    if (m % i == 0) {
      if (m / i >= n) {
        ans = max(ans, i);
      }
      if (i >= n) {
        ans = max(ans, m / i);
      }
    }
  }
  cout << ans << endl;
  return 0;
}
