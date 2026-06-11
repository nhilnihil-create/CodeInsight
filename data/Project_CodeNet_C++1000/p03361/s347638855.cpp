#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int H, W; cin >> H >> W; char table[H + 2][W + 2];
  
  for (int i = 0; i < H + 2; i++) {
    for (int j = 0; j < W + 2; j++) {
      table[i][j] = '.';
    }
  }
  
  for (int i = 1; i < H + 1; i++) {
    for (int j = 1; j < W + 1; j++) {
      char tmp; cin >> tmp;
      table[i][j] = tmp;
    }
  }
  
  for (int i = 1; i < H + 1; i++) {
    for (int j = 1; j < W + 1; j++) {
      
      char tmp = table[i][j];
      
      if (tmp == '.') continue;
      
      bool flag = true;
      
      char top = table[i - 1][j], bottom = table[i + 1][j];
      
      char left = table[i][j - 1], right = table[i][j + 1];
      
      if (top == '#' || bottom == '#' || left == '#' || right == '#') {
        flag = false;
      }
      
      if (flag) {
        cout << "No" << endl;
        return 0;
      }
      
    }
  }
  
  cout << "Yes" << endl;
  
}