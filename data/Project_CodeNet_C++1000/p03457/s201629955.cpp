#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  int n;
  cin >> n;

  vector<array<int, 3>> vp(n);
  for (auto &p : vp) {
    cin >> p[0] >> p[1] >> p[2];
  }

  int t = 0, x = 0, y = 0;
  bool ans = true;
  for (auto &p : vp) {
    int tt = p[0] - t;
    int dist = abs(x - p[1]) + abs(y - p[2]);
    if (dist > tt || (tt - dist) % 2 == 1) {
      ans = false;
      break;
    }

    t = p[0];
    x = p[1];
    y = p[2];
  }

  if (ans) {
    cout << "Yes" << '\n';
  } else {
    cout << "No" << '\n';
  }
}