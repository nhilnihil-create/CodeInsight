#include <iostream> 
#include <vector>
#include <utility>
#include <queue>
#include <string>

using namespace std;

int main () {
  int H, W; cin >> H >> W;

  vector<vector<int>> board(H, vector<int>(W));

  int n_white = 0;
  for (int i = 0; i < H; i++) {
    string str; cin >> str; 
    for (int j = 0; j < W; j++) {
      if (str.at(j) == '#') {
        board[i][j] = -1; // -1 is blocked
      } else { // '.'
        board[i][j] = -2; // -2 is open 
        n_white++;
      }
    }
  }

  queue<pair<int, int>> q; 
  q.push(make_pair(0, 0));
  board[0][0] = 0; // n >= 0 to signify travelling distance from (0, 0) 

  int ans = -1;
  while (!q.empty()) {
    auto p = q.front(); q.pop(); 
    int r = p.first; 
    int c = p.second; 
    int step = board[r][c] + 1;

    if (r == H - 1 && c == W - 1) {
      ans = n_white - step;
      break; 
    }

    if (r > 0 && board[r - 1][c] == -2) {
      board[r - 1][c] = step;
      q.push(make_pair(r - 1, c));
    }
    if (r < H - 1 && board[r + 1][c] == -2) {
      board[r + 1][c] = step;
      q.push(make_pair(r + 1, c));
    }
    if (c > 0 && board[r][c - 1] == -2) {
      board[r][c - 1] = step;
      q.push(make_pair(r, c - 1));
    }
    if (c < W - 1 && board[r][c + 1] == -2) {
      board[r][c + 1] = step; 
      q.push(make_pair(r, c + 1));
    }
  }

  cout << ans << endl;
}