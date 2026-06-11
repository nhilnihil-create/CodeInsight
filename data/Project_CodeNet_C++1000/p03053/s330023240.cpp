#include<bits/stdc++.h>
using namespace std;
int main() {
  int H, W; cin >> H >> W;
  vector<vector<int>> grid(H, vector<int> (W, -1));
  queue<pair<int, int>> black;
  for(int i = 0; i < H; i++) {
    for(int j = 0; j < W; j++) {
      char c; cin >> c;
      if(c == '#') {
        grid.at(i).at(j) = 0;
        black.push(make_pair(i, j));
      }
    }
  }
  vector<int> dx = {0, 1, 0, -1}, dy = {-1, 0, 1, 0};
  while(!black.empty()) {
    auto st = black.front();
    black.pop();
    for(int i = 0; i < 4; i++) {
      int px = st.first + dx.at(i);
      int py = st.second + dy.at(i);
      if(px >= 0 && px < H && py >= 0 && py < W) {
        if(grid.at(px).at(py) == -1) {
          grid.at(px).at(py) = grid.at(st.first).at(st.second) + 1;
          black.push(make_pair(px, py));
        }
      }
    }
  }
  int count = 0;
  for(int i = 0; i < H; i++) {
    for(int j = 0; j < W; j++) {
      count = max(count, grid.at(i).at(j));
    }
  }
  cout << count << endl;
}