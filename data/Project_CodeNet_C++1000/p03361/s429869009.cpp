#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  vector<string> S(H);
  for (int i = 0; i < H; i++) cin >> S.at(i);
  vector mh = {-1, 0, 1, 0};
  vector mw = {0, 1, 0, -1};
  for (int h = 0; h < H; h++) {
    for (int w = 0; w < W; w++) {
      if (S.at(h).at(w) == '#') {
        bool b = 0;
        for (int i = 0; i < 4; i++) {
          int nh = h + mh.at(i);
          int nw = w + mw.at(i);
          if (nh < 0 || nh >= H || nw < 0 || nw >= W) continue;
          if (S.at(nh).at(nw) == '#') b = 1;
        }
        if (!b) return cout << "No" << "\n", 0;
      }
    }
  }
  cout << "Yes" << "\n";
}