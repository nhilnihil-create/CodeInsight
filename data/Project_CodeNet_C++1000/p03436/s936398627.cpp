#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
using namespace std;

const vector<int> dx = {1,0,-1,0};
const vector<int> dy = {0,1,0,-1};

int main()
{
  int h,w;
  cin >> h >> w;
  vector<string> mass(h);
  for(int i=0;i<h;i++) cin >> mass[i];

  queue<pair<int,int>> que;
  vector<vector<int>> dist(h,vector<int>(w));
  for(int i=0;i<h;i++) dist[i].assign(w,-1);

  int black = 0;
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      if(mass[i][j] == '#') black++;
    }
  }

  //初期条件
  que.push(make_pair(0,0));
  dist[0][0] = 0;

  while(!que.empty()){
    pair<int,int> p = que.front();
    que.pop();

    int x = p.first;
    int y = p.second;

    for(int dir=0;dir<4;dir++){
      int nx = x + dx[dir];
      int ny = y + dy[dir];

      if(nx < 0 || nx >= h || ny < 0 || ny >= w) continue;

      if(dist[nx][ny] != -1) continue;
      if(mass[nx][ny] == '#') continue;

      dist[nx][ny] = dist[x][y] + 1;
      que.push(make_pair(nx,ny));
    }
  }

  if(dist[h-1][w-1] == -1) cout << "-1\n";
  else cout << h*w - black - (dist[h-1][w-1]+1) << endl;

}
