#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<char>> grid(H + 2, vector<char>(W + 2));
  
  for (int j = 0; j < W + 2; j++){
      grid.at(0).at(j) = '.';
  }
  for (int i = 1; i <= H; i++){
    grid.at(i).at(0) = '.';
    for (int j = 1; j <= W; j++){
      cin >> grid.at(i).at(j);
    }
    grid.at(i).at(W + 1) = '.';
  }
  for (int j = 0; j < W + 2; j++){
      grid.at(H + 1).at(j) = '.';
  }
  
  for (int i = 1; i < H + 1; i++){
    for (int j = 1; j < W + 1; j++){
      if (grid.at(i).at(j) == '#' && grid.at(i - 1).at(j) == '.'
          && grid.at(i + 1).at(j) == '.' && grid.at(i).at(j - 1) == '.'
          && grid.at(i).at(j + 1) == '.'){
        cout << "No" << endl;
        return 0;
      }
    }
  }
  cout << "Yes" << endl;
        return 0;
  
}
