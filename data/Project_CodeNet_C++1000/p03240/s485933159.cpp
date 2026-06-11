#pragma GCC optimize("Ofast")
#pragma GCC target("avx2,tune=native")
 
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int N;
  cin >> N;
  int x[N], y[N], h[N], XX = -1, YY = -1, HH = -1;
  for (int i = 0; i < N; i++) {
    cin >> x[i] >> y[i] >> h[i];
    if (h[i]) {
      XX = x[i];
      YY = y[i];
      HH = h[i];
    }
  }
  int height, expected;
  for (int i = 0; i <= 100; i++) {
    for (int j = 0; j <= 100; j++) {
      height = HH + abs(XX - i) + abs(YY - j);
      int k;
      for (k = 0; k < N; k++) {
        expected = max(height - abs(x[k] - i) - abs(y[k] - j), 0);
        if (h[k] != expected)
          break;
      }
      if (k == N) {
        cout << i << ' ' << j << ' ' << height;
        exit(EXIT_SUCCESS);
      }
    }
  }
  return 0;
}
