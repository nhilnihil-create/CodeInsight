#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<pair<int, int>> move = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
  int                    H, W;
  cin >> H >> W;
  vector<string> s(H);
  for (int i = 0; i < H; i++) {
    cin >> s.at(i);
  }
  bool ans = true;
  for (int ih = 0; ih < H; ih++) {
    for (int iw = 0; iw < W; iw++) {
      if (s.at(ih).at(iw) == '.') continue;
      ans = false;
      for (int im = 0; im < move.size(); im++) {
        int h = ih + move.at(im).first;
        int w = iw + move.at(im).second;
        if (h < 0 || H <= h) continue;
        if (w < 0 || W <= w) continue;
        if (s.at(h).at(w) == '#') {
          ans = true;
          break;
        }
      }
      if (!ans) break;
    }
    if (!ans) break;
  }
  cout << (ans ? "Yes" : "No") << endl;
}