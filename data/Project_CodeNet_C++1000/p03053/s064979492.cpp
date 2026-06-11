#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int dist[1005][1005];
queue<pair<int,int> > q;
int dx[] = {-1,0,1,0};
int dy[] = {0,-1,0,1};
int R, C;

bool inside(int r, int c){
  return 1<=r && r<=R && 1<=c && c<=C;
}

int bfs(){
  int ans = 0;
  while(!q.empty()){
    auto pos = q.front();
    q.pop();
    int row = pos.first;
    int col = pos.second;
    ans = max(ans, dist[row][col]);

    for(int d=0; d<4; d++){
      int nxr = row+dx[d];
      int nxc = col+dy[d];
      if(!inside(nxr, nxc)) continue;
      if(dist[nxr][nxc] != -1) continue;
      dist[nxr][nxc] = dist[row][col] + 1;
      q.push(make_pair(nxr, nxc));
    }
  }
  return ans;
}

int main() {
  cin >> R >> C;
  memset(dist, -1, sizeof(dist));
  for(int i=1; i<=R; i++){
    for(int j=1; j<=C; j++){
      char input;
      cin >> input;
      if(input == '#'){
        dist[i][j] = 0;
        q.push(make_pair(i,j));
      }
    }
  }

  cout << bfs() << endl;
}