#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
 
int main() {
  ios::sync_with_stdio(0); 
  cin.tie(0); 

  int h, w;
  cin >> h >> w;

  queue<pair<int, int>> q;
  char board[h][w];

  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      cin >> board[i][j];
      if (board[i][j] == '#') q.push({i, j});
    }
  }

  int dirs[8][2] = {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};

  while (!q.empty()) {
    pair<int, int> p = q.front(); q.pop();

    for (int k = 0; k < size(dirs); ++k) {
      int i = p.first + dirs[k][0], j = p.second + dirs[k][1];

      if (i >= 0 && i < h && j >= 0 && j < w && board[i][j] != '#') {
        if (board[i][j] == '.') board[i][j] = '1';
        else board[i][j] = (int) board[i][j] + 1;
      }
    }
  }

  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      if (board[i][j] == '.') cout << 0;
      else cout << board[i][j];
    }
    cout << "\n";
  }
}
