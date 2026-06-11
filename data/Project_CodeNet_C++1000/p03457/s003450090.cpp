#include <iostream>
#include <vector>
using namespace std;

int dist(int x1, int y1, int x2, int y2) {
  return abs(x2 - x1) + abs(y2 - y1);
}

int main() {
  int N;
  cin >> N;
  int pt = 0;
  int px = 0;
  int py = 0;
  bool ok = true;
  for (int i = 0; i < N; i++) {
    int t, x, y;
    cin >> t >> x >> y;
    int d = dist(px, py, x, y);
    if (t - pt >= d && (t - pt - d) % 2 == 0) {
    } else {
      ok = false;
      break;
    }
    pt = t;
    px = x;
    py = y;
  }
  cout << (ok ? "Yes" : "No") << endl;
}
