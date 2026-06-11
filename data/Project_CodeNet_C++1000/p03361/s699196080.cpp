#include <bits/stdc++.h>
using namespace std;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
// 上下左右用
const int hmax = 50;
const int wmax = 50;

int main() {
  int H, W;
  cin >> H >> W;

  //vector<vector<char>> s(H, vector<char>(W));
  char s[wmax][hmax];
  for(int i = 0; i < H; i++){
    for(int j = 0; j < W; j++){
      cin >> s[i][j];
    }
  }

  for(int i = 0; i < H; i++){
    for(int j = 0; j < W; j++){
      if(s[i][j] == '#'){
        int cnt = 0;
        for(int x = 0; x < 4; x++){
          if(s[i+dx[x]][j+dy[x]] == '#') cnt++;
        }
        if(cnt == 0){
          cout << "No" << endl;
          return 0;
        }
      }
    }
  }
  cout << "Yes" << endl;

}
