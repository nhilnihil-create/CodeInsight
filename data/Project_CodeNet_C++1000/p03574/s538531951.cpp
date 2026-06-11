#include <bits/stdc++.h>
using namespace std;

vector<vector<char>> v_input_mine(int h, int w) {
  vector<vector<char>> v(h + 2, vector<char>(w + 2));
  for (int i = 1; i <= h; i++) {
    for (int j = 1; j <= w; j++) {
      cin >> v.at(i).at(j);
      char dot = '.';
    }
  }
  return v;
}

int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<char>> V = v_input_mine(H, W); 
  vector<vector<int>> NUM(H + 2, vector<int>(W + 2, 0));
  char mine = '#';
  
  for (int i = 1; i <= H; i++) {
    for (int j = 1; j <= W; j++) {
      if (V.at(i).at(j) == mine) {
        NUM.at(i).at(j) = -1;
        for (int m = i - 1; m <= i + 1; m++) {
          for (int n = j - 1; n <= j + 1; n++) {
            if (V.at(m).at(n) != mine) {
              NUM.at(m).at(n)++;
            }
          }
        }
      }
    }
  }
  
  for (int i = 1; i <= H; i++) {
    for (int j = 1; j <= W; j++) {
      if (NUM.at(i).at(j) == -1) {
        cout << '#';
      }
      else {
        cout << NUM.at(i).at(j);
      }
    }
    cout << endl;
  }
}
