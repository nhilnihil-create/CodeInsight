#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int dx[4]={ 0, 1,  0, -1};
int dy[4]={ 1, 0, -1,  0};
using P = pair<int,int>;
int h, w, n;
int sx, sy, gx, gy;
int ans=0, cnt=0;
char c[50][50];
queue<P> que;

int main(){
  cin >> h >> w;
  sx = 0, sy = 0, gx = w-1, gy = h-1;
  for(int i=0; i<h; i++){
    for(int j=0; j<w; j++){
      cin >> c[j][i];
      if(c[j][i] == '.') cnt++;
    }
  }
  queue<P> que;
  vector<vector<int>> d(w, vector(h, -1));
  d[sx][sy] = 1;
  que.push(P(sx, sy));
  while(!que.empty()){
    P p = que.front();
    que.pop();
    int px = p.first, py = p.second;
    if(px==gx && py==gy){
      ans += d[px][py];
      sx = px, sy = py;
      break;
    }
    for(int i=0; i<4; i++){
      int nx = px+dx[i], ny = py+dy[i];
      if(ny < 0 || ny >= h || nx < 0 || nx >= w) continue;
      if(c[nx][ny] == '#' || d[nx][ny] != -1) continue;
      d[nx][ny] = d[px][py] + 1;
      que.push(P(nx, ny));
    }
  }
  if(d[gx][gy] == -1) cout << -1 << endl;
  else cout << cnt-ans << endl; 
}