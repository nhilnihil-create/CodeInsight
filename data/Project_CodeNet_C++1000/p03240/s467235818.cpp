#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n;
  cin >> n;
  vector<int> x(n), y(n), h(n);
  rep(i, n) cin >> x[i] >> y[i] >> h[i];

  for (int cx = 0; cx <= 100; ++cx) {
    for (int cy = 0; cy <= 100; ++cy) {
      int H = 2e9;
      rep(i, n) H = min(H, h[i] + abs(x[i] - cx) + abs(y[i] - cy));
      if (H == 0) continue;
      bool ok = true;
      rep(i, n) if (h[i] != max(H - abs(x[i] - cx) - abs(y[i] - cy), 0)) ok = false;
      if (ok) {
        printf("%d %d %d\n", cx, cy, H);
      }
    }
  }
  return 0;
}