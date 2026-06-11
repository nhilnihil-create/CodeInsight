#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, h, w; cin >> n >> h >> w;
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    int x, y; cin >> x >> y;
    if (h <= x && w <= y) cnt++;
  }
  cout << cnt << endl;
  return 0;
}