#include <iostream>
#include <string>
using namespace std;

int main(){
  int H, W;
  string S[50];
  int cnt[50][50] = {};
  int dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
  int dy[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
  
  cin >> H >> W;
  for(int i = 0; i < H; i++) cin >> S[i];
  
  for(int i = 0; i < H; i++){
    for(int j = 0; j < W; j++){
      if(S[i][j] == '.'){
        for(int k = 0; k < 8; k++){
          int x = j + dx[k], y = i + dy[k];
          if((0 <= x && x < W) && (0 <= y && y < H) && S[y][x] == '#') cnt[i][j]++;
        }
      }else cnt[i][j] = -1;
    }
  }
  
  for(int i = 0; i < H; i++){
    for(int j = 0; j < W; j++){
      if(cnt[i][j] == -1) cout << '#';
      else cout << cnt[i][j];
    }
    cout << endl;
  }
  cout << endl;
  
  return 0;
}