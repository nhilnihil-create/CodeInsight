#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {
  int H, W;
  vector<vector<char>> board;
  cin >> H >> W;
  board = vector<vector<char>>(H, vector<char>(W));
  int dot_count = 0;
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> board[i][j];
      if (board[i][j] == '.') {
        dot_count++;
      }
    }
  }

  int step = 0;
  board[0][0] = '*';
  queue<pair<int, int>> que;
  que.push(make_pair(0, 0));
  while (!que.empty()) {
    step++;
    queue<pair<int, int>> tmp;
    while (!que.empty()) {
      pair<int, int> pos = que.front();
      que.pop();
      int x = pos.first;
      int y = pos.second;

      if (x == H - 1 && y == W - 1) {
        cout << dot_count - step << endl;
        return 0;
      }

      if (x + 1 < H && board[x + 1][y] == '.') {
        board[x + 1][y] = '*';
        tmp.push(make_pair(x + 1, y));
      }
      if (y + 1 < W && board[x][y + 1] == '.') {
        board[x][y + 1] = '*';
        tmp.push(make_pair(x, y + 1));
      }
      if (0 <= x - 1 && board[x - 1][y] == '.') {
        board[x - 1][y] = '*';
        tmp.push(make_pair(x - 1, y));
      }
      if (0 <= y - 1 && board[x][y - 1] == '.') {
        board[x][y - 1] = '*';
        tmp.push(make_pair(x, y - 1));
      }
    }
    que.swap(tmp);
  }

  cout << "-1" << endl;

  return 0;
}