#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int H,W;
  cin >> H >> W;
  vector<vector<char>> data(H, vector<char>(W));
 
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> data.at(i).at(j);
      if (data.at(i).at(j) == '.') {
        data.at(i).at(j) = '0';
      }
    }
  }
  
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (data.at(i).at(j) == '#') {
        for (int x = i-1; x <= i+1; x++) {
          if (x >= 0 && x < H) {
            for (int y = j-1; y <= j+1; y++) {
              if (y >= 0 && y < W) {
                if (data.at(x).at(y) != '#') {
                  data.at(x).at(y)++;
                }
              }
            }
          }
        }  
      }
    }
  }
  
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cout << data.at(i).at(j);
      if (j == W - 1) {
      cout << endl;
      }
    }    
  }
}