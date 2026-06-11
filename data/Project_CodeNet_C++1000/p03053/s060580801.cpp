# include <iostream>
# include <cstring>
# include <queue>

using namespace std;
# define pii pair<int,int>
int R, C;
char grid[1005][1005];
int dis[1005][1005];
int dx[] = {-1,0,1,0};
int dy[] = {0,-1,0,1};

bool inside(int r, int c){
  return 1 <= r && r <= R && 1 <= c && c <= C;
}

int main(){
  cin >> R >> C;
  queue<pii> q;
  memset(dis, -1, sizeof(dis));

  for(int i=1; i<=R; i++){
    for(int j=1; j<=C; j++){
      cin >> grid[i][j];
      if(grid[i][j] == '#'){
        q.push({i,j});
        dis[i][j] = 0;
      }
    }
  }

  int ans = 0;
  while(!q.empty()){
    pii cur = q.front();
    q.pop();

    int r = cur.first, c = cur.second;
    ans = max(ans, dis[r][c]);
    for(int d=0; d<4; d++){
      int nxr = r+dx[d];
      int nxc = c+dy[d];
      if(!inside(nxr, nxc)) continue;
      if(dis[nxr][nxc] != -1) continue;
      if(grid[nxr][nxc] == '#') continue;

      dis[nxr][nxc] = dis[r][c] + 1;
      q.push({nxr, nxc});
    }
  }

  cout << ans << endl;
  return 0;
}