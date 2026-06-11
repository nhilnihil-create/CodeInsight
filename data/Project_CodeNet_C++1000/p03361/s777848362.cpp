#include <bits/stdc++.h>
using namespace std;
int h, w;
int dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0};
int main(){
  cin >> h >> w;
  string M[h];
  for(int i=0; i<h; ++i) cin >> M[i];
  for(int y=0; y<h; ++y){
    for(int x=0; x<w; ++x){
      bool judge = [&]{
        for(int i=0; i<4; ++i){
          int nx = x+dx[i], ny = y+dy[i];
          if(nx < 0 || nx >= w || ny < 0 || ny >= h) continue;
          if(M[ny][nx] == '#') return false;
        }
        return true;
      }();
      if(M[y][x] == '#' && judge){ cout << "No" << endl; return 0; }
    }
  }
  cout << "Yes" << endl;
}