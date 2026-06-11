#include <bits/stdc++.h>
using namespace std;

vector<string> maze(60);
vector<vector<int>> d(60,vector<int>(60,-1));
int h,w;

struct P {
  int y,x;
};
int dx[]={1,0,-1,0},dy[]={0,1,0,-1};

void bfs() {
  queue<P> Q;
  Q.push({0,0});
  d[0][0]=0;
  P now;
  while(!Q.empty()) {
    now=Q.front(); Q.pop();
    for(int i=0;i<4;i++) {
      int ny=now.y+dy[i];
      int nx=now.x+dx[i];
      if(ny>=0&&ny<h&&nx>=0&&nx<w&&d[ny][nx]==-1&&maze[ny][nx]=='.') {
        Q.push({ny,nx});
        d[ny][nx]=d[now.y][now.x]+1;
      }
    }
  }
}

int main() {
  cin>>h>>w;
  int white=0;
  for(int i=0;i<h;i++) {
    cin>>maze[i];
    for(int j=0;j<w;j++) {
      if(maze[i][j]=='.') white++;
    }
  }
  bfs();
  if(d[h-1][w-1]==-1) cout<<-1;
  else cout<<white-d[h-1][w-1]-1<<endl;
}
