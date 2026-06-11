#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  char S;
  cin >> H >> W;
  
  vector<vector<int>> data(H+2, vector<int>(W+2));
  
  for (int i = 0; i < H+2; i++) {
    for (int j = 0; j < W+2; j++) {
      data.at(i).at(j) = 0;
    }
  }
  
  for (int i = 1; i < H+1; i++) {
    for (int j = 1; j < W+1; j++) {
      cin >> S;
      if (S == '#') {
        data.at(i).at(j) = 10;
        data.at(i-1).at(j-1)++;
        data.at(i-1).at(j)++;
        data.at(i-1).at(j+1)++;
        data.at(i).at(j-1)++;
        data.at(i).at(j+1)++;
        data.at(i+1).at(j-1)++;
        data.at(i+1).at(j)++;
        data.at(i+1).at(j+1)++;
      } 
    }
  }
  
  for (int i = 1; i < H+1; i++) {
    for (int j = 1; j < W+1; j++) {
      if (data.at(i).at(j) < 10) {
        cout << data.at(i).at(j);
      } else {
        cout << '#';
      }
    }
    cout << endl;
  }
}
