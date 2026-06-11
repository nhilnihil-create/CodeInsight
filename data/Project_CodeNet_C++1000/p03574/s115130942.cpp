#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  
  vector<string> board(H);
  
  vector<int> dx = {-1, 1, 0, 0, -1, 1, -1, 1};
  vector<int> dy = {0, 0, -1, 1, -1, -1, 1, 1};
  
  for (int i = 0; i < H; i++) {
    cin >> board[i];
  }
  
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (board[i][j] == '#') continue;
      
      int num = 0;
      for (int d = 0; d < 8; d++) {
        const int ni = i + dy[d];
        const int nj = j + dx[d];
        
        if (ni >= H || ni < 0) continue;
        if (nj >= W || nj < 0) continue;
        if (board[ni][nj] == '#') num++;
      }
      board[i][j] = char(num + '0');
    }
  }
  
  for (int i = 0; i < H; i++) cout << board[i] << endl;
}