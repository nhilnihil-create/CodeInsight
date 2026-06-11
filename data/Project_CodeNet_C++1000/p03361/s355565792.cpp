#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int H, W;
  cin >> H >> W;
  vector<string> word(50);
  for (int i = 0; i < H; i++) {
    cin >> word.at(i);
  }
  vector<int> dh = {-1, 0, 0, 1};
  vector<int> dw = {0, -1, 1, 0};
  bool result = true;
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      int b = 0;
      if (word.at(i).at(j) == '.') continue;
      for (int k = 0; k < 4; k++) {
        const int i4 = i + dh.at(k);
        const int j4 = j + dw.at(k);
        if ((i4 < 0) || (i4 >= H)) continue;
        if ((j4 < 0) || (j4 >= W)) continue;

        if (word.at(i4).at(j4) == '#') {
          b++;
        }
        
      }
      if (b == 0) {
        result = false;
      }
    }
  }
  if (result) {
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }
          
        
      
  return 0;
}