#include <bits/stdc++.h>
#include <cstdlib>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<char>> data(H, vector<char>(W));
  
  for (int i = 0; i < H; i++) {
  	for (int j = 0; j < W; j++) {
    	cin >> data.at(i).at(j);
    }
  }
  
  bool a = true;
  int num = 0;
  for (int i = 0; i < H; i++) {
  	for (int j = 0; j < W; j++) {
      if (data.at(i).at(j) == '.') continue;
      
      for (int k = -1; k <= 1; k++) {
        if (i + k == -1 || i + k == H) continue;
      	for (int l = -1; l <= 1; l++) {
          if (j + l == -1 || j + l == W) continue;
          if (k * l != 0) continue;
          if (data.at(i + k).at(j + l) == '#') num++;
        }
      }
      
      if (num == 1) a = false;
      num = 0;
    }
  }
  if (a == true) cout << "Yes" << endl;
  else cout << "No" << endl;
}
