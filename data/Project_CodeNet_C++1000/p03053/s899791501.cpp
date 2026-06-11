#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
using namespace std;
using ll = long long;

const vector<int> dx = {1,0,-1,0};
const vector<int> dy = {0,1,0,-1};

int main() {
  int h,w;
  cin >> h >> w;
  vector<string> a(h);
  for(int i=0;i<h;i++) cin >> a[i];

  queue<pair<int,int>> que;
  vector<vector<int>> dist(h,vector<int>(w));
  for(int i=0;i<h;i++) dist[i].assign(w,-1);

  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      if(a[i][j] == '#'){
        que.push(make_pair(i,j));
        dist[i][j] = 0;
      }
    }
  }

  while(!que.empty()){
    pair<int,int> v = que.front();
    que.pop();

    int x = v.first;
    int y = v.second;

    for(int dir=0;dir<4;dir++){
      int nx = x + dx[dir];
      int ny = y + dy[dir];

      if(nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
      if(a[nx][ny] == '#') continue;

      if(dist[nx][ny] != -1){
        if(dist[nx][ny] > dist[x][y] + 1){
          dist[nx][ny] = dist[x][y] + 1;
        }else{
          continue;
        }
      }else{
        dist[nx][ny] = dist[x][y] + 1;
      }

      que.push(make_pair(nx,ny));
    }

  }

  int ans = 0;
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      ans = max(ans,dist[i][j]);
    }
  }
  cout << ans << endl;

}