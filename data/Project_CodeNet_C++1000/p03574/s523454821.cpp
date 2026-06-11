#include <bits/stdc++.h>
using namespace std;

int main(){
  int dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
  int dy[8] = {1,1,1,0,0,-1,-1,-1};
  int h, w; cin >> h >> w;
  string s[h];
  for(int i = 0; i < h; ++i){
     cin >> s[i];
  }
  int ans[h][w] = {};
  for(int y = 0; y < h; ++y){
    for(int x = 0; x < w; ++x){
      int num = 0;
      for(int j = 0; j < 8; ++j){
        if(s[y][x] == '#') {
          num = -1;
          continue;
        }
        if(y + dy[j] < 0 || y + dy[j] >= h) continue;
        if(x + dx[j] < 0 || x + dx[j] >= w) continue;
        int xx = x + dx[j];
        int yy = y + dy[j];
        if(s[yy][xx] == '#') ++num;
      }
      ans[y][x] = num;
    }
  }
  for(int i = 0; i < h; ++i){
    for(int j = 0; j < w; ++j){
      if(ans[i][j] == -1) cout << '#';
      else cout << ans[i][j];
    }
    cout << '\n';
  }
  return 0; 
}
