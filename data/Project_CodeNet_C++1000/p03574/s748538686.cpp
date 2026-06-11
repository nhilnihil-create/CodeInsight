#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  
  vector<string> vec(H);
  for (int i=0; i < H; i++) {
    cin >> vec.at(i);
  }
  
  int count;
  char buf;
  // main loop
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (vec.at(i).at(j) == '.') { 
        count = 0;
        for (int di = -1; di <= 1; di++) {
          for (int dj = -1; dj <= 1; dj++) {
            if (i + di >= 0 && i + di < H && j + dj >= 0 && j + dj < W) {
              if (vec.at(i+di).at(j+dj) == '#') {
                count++;
              }
            }
          }
        }
        vec.at(i).at(j) = to_string(count).at(0);
      }
    }
  }
  
  for (int i = 0; i < H; i++) {
    cout << vec.at(i) << endl;
  }
}
