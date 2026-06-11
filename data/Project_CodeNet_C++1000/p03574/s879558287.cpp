#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;

  string enpty_S = "";
  for (int i = 0; i < W; i++) {
    enpty_S += ".";
  }

  string prev_S = enpty_S;
  string current_S;
  string next_S;

  cin >> current_S;

  for (int i = 0; i < H; i++) {
    if (i == H - 1) {
      next_S = enpty_S;
    } else {
      cin >> next_S;
    }

    for (int j = 0; j < W; j++) {
      char current_grid = current_S.at(j);
      if (current_grid == '#') {
        cout << current_grid;
        continue;
      }

      int mines_count = 0;
      for (int k = j - 1; k <= j + 1; k++) {
        if (k < 0) {
          continue;
        } else if (k == W) {
          break;
        }
        if (prev_S.at(k) == '#') {
          mines_count++;
        }
        if (current_S.at(k) == '#') {
          mines_count++;
        }
        if (next_S.at(k) == '#') {
          mines_count++;
        }
      }
      cout << mines_count;
    }
    cout << endl;

    prev_S = current_S;
    current_S = next_S;
  }
}