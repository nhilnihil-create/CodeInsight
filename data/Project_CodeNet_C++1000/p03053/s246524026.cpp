#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

char grid[1005][1005];
int R, C;
int shortestpath[1005][1005];

int mr[4] = {0, -1, 0, 1};
int mc[4] = {1, 0 , -1, 0};

bool inside (int r, int c){
  if (r < 0 || r >= R || c < 0 || c >= C)
    return false;
  return true;
}

queue < pair <int, int>> w;

int bfs (queue<pair<int,int> > w){
  int ans = 0;
  while(!w.empty()){
    pair<int,int> now = w.front();
    w.pop();
    ans = max(ans, shortestpath[now.first][now.second]);
    for(int i=0; i<4; i++){
      int nxr = now.first + mr[i];
      int nxc = now.second + mc[i];
      if(!inside(nxr, nxc)) continue;
      if(shortestpath[nxr][nxc] != -1) continue;
      shortestpath[nxr][nxc] = shortestpath[now.first][now.second] + 1;
      w.push(make_pair(nxr, nxc));
    }
  }
  return ans;
}

int main() {
  cin >> R >> C;

  memset(shortestpath, -1, sizeof(shortestpath));
  for (int i = 0; i < R; i++){
    for (int j = 0; j < C; j++){
      cin >> grid[i][j];
      if (grid[i][j] == '#'){
        shortestpath[i][j] = 0;
        w.push(make_pair (i,j));
      }
    }
  }

  
  cout << bfs(w) << endl;

  return 0;
}
