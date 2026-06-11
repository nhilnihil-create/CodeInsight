#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;

  vector<string> s(H);
  
  for (int i = 0; i < H; i++) {
	cin >> s.at(i);
  }

  // 調べつつ書く
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      char c = s.at(i).at(j);
      if (c == '.') {
        // 数える
        int sum = 0;
        for (int y = -1; y <= 1; y++) {
          for (int x = -1; x <= 1; x++) {
            if (0 == x && 0 == y) {
              continue;
            }
            int posx = j + x;
            int posy = i + y;
            if (posx < 0 || posy < 0 || posx > (W - 1) || posy > (H - 1)) {
              continue;
            }
            if (s.at(posy).at(posx) == '#')
              sum++;
          }
        }
        cout << sum;
      } else {
        cout << "#";
      }
    }
    cout << endl;
  }
}
