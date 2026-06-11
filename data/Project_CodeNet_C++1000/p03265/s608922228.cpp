#include <iostream>

using namespace std;

void solve() {
  int x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;

  printf("%d %d %d %d\n", x2 + (y1-y2), y2 - (x1-x2), x1 + (y1-y2), y1- (x1-x2));
}

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}
