#include <bits/stdc++.h>
using namespace std;
int main() {
  int H,W;
  cin >> H >> W;
  vector<vector<char>> S(H, vector<char>(W));
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> S.at(i).at(j);
    }
  }
  
  vector<vector<int>> data(H+2, vector<int>(W+2,0));
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (S.at(i).at(j) == '#'){
        data.at(i+1).at(j+1)+=100;
        data.at(i+1).at(j)++;
        data.at(i+1).at(j+2)++;
        data.at(i).at(j+1)++;
        data.at(i+2).at(j+1)++;
        data.at(i).at(j)++;
        data.at(i+2).at(j)++;
        data.at(i+2).at(j+2)++;
        data.at(i).at(j+2)++;
      }
    }
  }
  
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (data.at(i+1).at(j+1) >= 100){
        cout << '#';
      }
      else {
        cout << data.at(i+1).at(j+1);
      }
      if (j == W-1){
        cout << endl;
      }
    }
  }
}
  