#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
char grid[1005][1005];
# define pii pair<int,int>

int shortestPath[1005][1005];
int R, C;
int dx[] = {-1,0,1,0};
int dy[] = {0,-1,0,1};

bool inside(int r, int c){
  return 0<=r && r<R && 0<=c && c<C;
}

int bfs(){
  queue<pii> q;
  memset(shortestPath, -1, sizeof(shortestPath));

  for(int i=0; i<R; i++){
    for(int j=0; j<C; j++){
      if(grid[i][j] == '#'){
        shortestPath[i][j] = 0;
        q.push(make_pair(i, j));
      }
    }
  }
  
  int ans = 0;
  while(!q.empty()){
    pii now = q.front(); q.pop();
    int row = now.first;
    int col = now.second;

    ans = max(ans, shortestPath[row][col]);

    for(int d = 0; d < 4; d++){
      int nxr = row+dx[d];
      int nxc = col+dy[d];
      if(!inside(nxr, nxc)) continue;
      if(shortestPath[nxr][nxc] != -1) continue;
      shortestPath[nxr][nxc] = shortestPath[row][col] + 1;
      q.push(make_pair(nxr, nxc));
    }
  }

  return ans;
}

int main() {
  cin >> R >> C;
  for(int i=0; i<R; i++){
    for(int j=0; j<C; j++){
      cin >> grid[i][j];
    }
  }

  cout << bfs() << endl;
}