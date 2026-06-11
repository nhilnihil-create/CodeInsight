#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
void err() {
  cout << 0 << '\n';
  exit(0);
}
signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int cnt[13] = {};
  int n;
  cin >> n;
  cnt[0]++;
  for (int i = 0; i < n; i++) {
    int in;
    cin >> in;
    cnt[in]++;
  }
  int d[24] = {};
  int prv = 0;
  for (int i = 0; i <= 12; i++) {
    if (i == 0 || i == 12) {
      if (cnt[i] >= 2) err();
      if (cnt[i]) d[i] = 1;
    } else {
      if (cnt[i] >= 3) err();
      if (cnt[i] == 2) {
        d[i] = 1;
        d[24 - i] = 1;
        prv = 0;
      }
      if (cnt[i] == 1) {
        if (prv == 0) {
          d[i] = 1;
          prv = 1;
        } else {
          d[24 - i] = 1;
          prv = 0;
        }
      }
    }
  }
  int ans = 1 << 30;
  for (int i = 0; i < 24; i++) {
    for (int j = 0; j < 24; j++) {
      if (i != j && d[i] && d[j]) ans = min(ans, abs(i - j));
    }
  }
  cout << ans << '\n';
  return 0;
}