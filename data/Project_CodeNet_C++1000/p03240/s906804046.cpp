#include<bits/stdc++.h>
using namespace std;
int main () {
  int N;
  cin >> N;
  vector<tuple<int, int, int>> pyra(N);
  for (int i = 0; i < N; i ++) {
    int x, y, h;
    cin >> x >> y >> h;
    pyra[i] = make_tuple(h, x, y);
  }
  sort(pyra.begin(), pyra.end());
  reverse(pyra.begin(), pyra.end());
  for (int x = 0; x <= 100; x ++) {
    for (int y = 0; y <= 100; y ++) {
      int cx, cy, ch;
      tie(ch, cx, cy) = pyra[0];
      int H;
      if (ch == 0) H = 1;
      else {
        int dex = max(x - cx, cx - x);
        int dey = max(y - cy, cy - y);
        H = ch + dex + dey;
      }
      bool ok = true;
      for (int i = 0; i < N; i ++) {
        tie(ch, cx, cy) = pyra[i];
        int dx = max(x - cx, cx - x);
        int dy = max(y - cy, cy - y);
        int dh = max(H - dx - dy, 0);
        if (dh != ch) ok = false;
      }
      if (ok) {
        cout << x << ' ' << y << ' ' << H << endl;
        return 0;
      }
    }
  }
}