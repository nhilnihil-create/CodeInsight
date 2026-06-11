#include <bits/stdc++.h>
using namespace std;

int dx[] = {0,1,0,-1}, dy[] = {1,0,-1,0};  
int H,W,countB =0,d[55][55];
char G[55][55];
vector<vector<bool>> seen(55,vector<bool>(55,false));

void bfs(int a,int b) {
  seen[a][b] = true;
  queue<pair<int,int>> Q;
  Q.push({a,b});
  while (!Q.empty()) {
    int x,y; tie(x,y) = Q.front(); Q.pop();
    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if(nx >= H || nx < 0 || ny >= W || ny < 0) continue;
      if(seen[nx][ny]) continue;
      if(G[nx][ny] == '#') continue;
      d[nx][ny] = d[x][y] + 1;
      seen[nx][ny] = true;
      Q.push({nx,ny});
    }
  }
}   

int main() {
  cin >> H >> W;
  for (int i =0; i<H; i++) {
    string tmp; cin >> tmp;
    for (int j =0; j<W; j++) {
      G[i][j] = tmp[j];
      if (tmp[j] =='#') countB++;
    }
  }
  
  d[0][0] =1;
  bfs(0,0);
  int ans;
  if (d[H-1][W-1] ==0) ans = -1;
  else ans = H * W - d[H-1][W-1] - countB; 
  cout << ans << endl;
}