#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int H, W;
  cin >> H >> W;
  
  vector<vector<char>> S(H, vector<char>(W));
  for(int i = 0; i < H; i++) {
    for(int j = 0; j < W; j++) {
      cin >> S.at(i).at(j);
    }
  }

  for(int i = 0; i < H; i++) {
    for(int j = 0; j < W; j++) {
      int c = 0; //地雷カウンタ
      if(S.at(i).at(j) == '#') {
        continue;
      }
      if(i > 0 && j > 0 && S.at(i-1).at(j-1) == '#') { //左上
        c++;
      } 
      if(i > 0 && S.at(i-1).at(j) == '#') {//真上
        c++;
      } 
      if(i > 0 && j < W-1 && S.at(i-1).at(j+1) == '#') { //右上
        c++;
      }
      if(j < W-1 && S.at(i).at(j+1) == '#') { //右横
        c++;
      } 
      if(i < H-1 && j < W-1 && S.at(i+1).at(j+1) == '#') { //右下
        c++;
      } 
      if(i < H-1 && S.at(i+1).at(j) == '#') { //真下
        c++;
      } 
      if(i < H-1 && j > 0 && S.at(i+1).at(j-1) == '#') { //左下
        c++;
      } 
      if(j > 0 && S.at(i).at(j-1) == '#') { //左横
        c++;
      }
      string c_str = to_string(c);
      S.at(i).at(j) = c_str.at(0);
    }
  }

  for(int i = 0; i < H; i++) {
    for(int j = 0; j < W; j++) {
      cout << S.at(i).at(j);
    }
    cout << endl;
  }

  return 0;
}