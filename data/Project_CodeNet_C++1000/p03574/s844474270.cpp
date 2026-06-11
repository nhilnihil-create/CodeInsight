#include <bits/stdc++.h>
using namespace std;
int h, w;
int dx[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
int dy[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
int main(){
  cin >> h >> w;
  string m[h];
  for(int i=0; i<h; ++i) cin >> m[i];
  for(int y=0; y<h; ++y){
    for(int x=0; x<w; ++x){
      if(m[y][x] == '#') continue;
      int nx, ny, sum = 0;
      for(int i=0; i<8; ++i){
        nx = x+dx[i]; ny = y+dy[i];
        if(nx < 0 || nx >= w || ny < 0 || ny >=h) continue;
        if(m[ny][nx] == '#') ++sum;
      }
      m[y][x] = '0'+sum;
    }
  }
  for(int i=0; i<h; ++i){
    cout << m[i] << endl;
  }
}