#include <bits/stdc++.h>
using namespace std;

int x[90010], y[90010], sum[90010];
int main() {
  int H, W, D;
  cin >> H >> W >> D;
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      int a;
      cin >> a;
      a--;
      x[a] = i;
      y[a] = j;
    }
  }
  for (int i = 0; i < H * W; i++) {
    if (i >= D) sum[i] = sum[i - D] + abs(x[i] - x[i - D]) + abs(y[i] - y[i - D]);
  }
  int Q;
  cin >> Q;
  while (Q--) {
    int l, r;
    cin >> l >> r;
    l--, r--;
    cout << sum[r] - sum[l] << endl;
  }
  return 0;
}
