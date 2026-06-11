#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  
  vector<string> s(H), c(H, string (W, '.'));
  for (auto&& in : s) cin >> in;
  
  vector<int> dy {1, 0, -1, 0}, dx {0, 1, 0, -1};
  
  for (int y = 0; y < H; y++) {
    for (int x = 0; x < W; x++) {
      if (s[y][x] == '#') {
        for (int direction = 0; direction < 4; direction++) {
          int new_y = y + dy[direction], new_x = x + dx[direction];
          if (new_y < 0 || new_x < 0 || H <= new_y || W <= new_x
             || s[new_y][new_x] == '.') continue;
          c[y][x] = c[new_y][new_x] = '#';
        }
      }
    } 
  }
  
  for (int y = 0; y < H; y++) {
    for (int x = 0; x < W; x++) {
      if (s[y][x] != c[y][x]) {
        cout << "No\n";
        return 0;
      }
    }
  }
  
  cout << "Yes\n";
  return 0;
}