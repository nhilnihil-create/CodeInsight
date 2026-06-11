#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  int h[n];
  int mx = 0;
  for (int i = 0; i < n; i++) {
    cin >> h[i];
    mx = max(mx, h[i]);
  }

  // 1マス分ずつ下げていく
  int ans = 0;
  for (int i = mx; i >= 1; i--) {
    int idx = 0;
    while (idx < n) {
      if (h[idx] == 0) {
        idx++;
      } else {
        ans++;
        while (idx < n && h[idx] > 0) {
          idx++;
        }
      }
    }
    for (int j = 0; j < n; j++) {
      if (h[j]) h[j]--;
    }
  }

  cout << ans << endl;
  return 0;
}