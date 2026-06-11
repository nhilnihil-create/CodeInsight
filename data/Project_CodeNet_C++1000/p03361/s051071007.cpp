#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;

int H, W;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> H >> W;
  string S[H];
  bool is_possible = true;

  for (int i = 0; i < H; i++) {
    cin >> S[i];
  }

  for (int h = 0; h < H; h++) {
    for (int w = 0; w < W; w++) {
      if (S[h][w] == '.') {
        continue;
      }
      int num = 0;
      for (int y = -1; y <= 1; y ++) {
        if (h + y < 0 || h + y > H - 1) {
          continue;
        }
        for (int x = -1; x <= 1; x ++) {
          if (w + x < 0 || w + x > W - 1) {
            continue;
          }
          if (x + y == -1 || x + y == 1) {
            if (S[h + y][w + x] == '#') {
              num++;
            }
          }
        }
      }
      if (num == 0) {
        is_possible = false;
      }
      if (!is_possible) {
        break;
      }
    }
    if (!is_possible) {
      break;
    }
  }
  if (is_possible) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}