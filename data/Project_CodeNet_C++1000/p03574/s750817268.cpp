//#include <bits/stdc++.h>
#include<iostream>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  string area[H];
  for(int i = 0; i < H; i++) {
    cin >> area[i];
  }
  int dir[][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}};
  for(int i = 0; i < H; i++) {
    for(int j = 0; j < W; j++) {
      if(area[i][j] == '.') {
        int count = 0;
        int h, w;
        for(int k = 0; k < 8; k++) {
          h = i + dir[k][0];
          w = j + dir[k][1];
          if(h >= 0 && h < H && w >= 0 && w < W) {
            if(area[h][w] == '#') {
              count++;
            }
          }
        }
        area[i][j] = char(count + '0');
      }
    }
  }
  for(int i = 0; i < H; i++) {
    cout << area[i] << endl;
  }
}
