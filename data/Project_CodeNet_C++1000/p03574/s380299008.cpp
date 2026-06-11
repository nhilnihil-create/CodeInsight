#include <iostream>
#include <string>
using namespace std;

int main(){
  int H, W;
  char c;
  int cnt[50][50] = {};
  int dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
  int dy[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
  
  cin >> H >> W;
  for(int i = 0; i < H; i++){
    for(int j = 0; j < W; j++){
      cin >> c;
      if(c == '#'){
        cnt[i][j] -= 9;
        for(int k = 0; k < 8; k++){
          int x = j + dx[k], y = i + dy[k];
          if((0 <= x && x < W) && (0 <= y && y < H)) cnt[y][x]++;
        }
      }
    }
  }
  
  for(int i = 0; i < H; i++){
    for(int j = 0; j < W; j++){
      if(cnt[i][j] < 0) cout << '#';
      else cout << cnt[i][j];
    }
    cout << endl;
  }
  
  return 0;
}