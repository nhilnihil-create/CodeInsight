#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  
  vector<vector<char>> field(H, vector<char>(W));
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> field[i][j];
    }
  }
  
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      int count = 0;
      if (field[i][j] == '#') continue;
      else {
        if (i > 0 && field[i-1][j] == '#') count++;
        if (i > 0 && j < W - 1 && field[i-1][j+1] == '#') count++;
        if (j < W - 1 && field[i][j+1] == '#') count++;
        if (i < H - 1 && j < W - 1 && field[i+1][j+1] == '#') count++;
        if (i < H - 1 && field[i+1][j] == '#') count++;
        if (i < H - 1 && j > 0 && field[i+1][j-1] == '#') count++;
        if (j > 0 && field[i][j-1] == '#') count++;
        if (i > 0 && j > 0 && field[i-1][j-1] == '#') count++;
      }
      
      field[i][j] = '0' + count;
    }
  }
  
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cout << field[i][j];
      if (j == W - 1) cout << endl;
    }
  }
}