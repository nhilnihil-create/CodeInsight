#include <iostream>
#include <queue>

using namespace std;

char s[50][50];
int d[50][50];

bool bfs(int sx, int sy, int h, int w){
    queue <pair<int, int> > q;
    int dx[4]={1,0,-1,0}, dy[4]={0,1,0,-1};
    h--;
    w--;

    for (int i = 0; i <= h; i++){
      for (int j = 0; j <= w; j++){
        d[i][j]=-1;
      }
    }
    
    q.push(make_pair(sx,sy));
    d[sx][sy]=0;

    while(!q.empty()){
        pair<int, int> p=q.front(); 
        q.pop();

        for (int i=0; i<4; i++){
            int nx=p.first+dx[i],ny=p.second+dy[i];

            if(0<=nx && nx<=h && 0<=ny && ny<=w && s[nx][ny]!='#' && d[nx][ny]==-1){
                q.push(make_pair(nx,ny));
                d[nx][ny]=d[p.first][p.second]+1;
            }
        }
    }

    if (d[h][w] != -1){
      return true;
    }else{
      return false;
    }
}

int main(){
  int H, W;
  cin >> H >> W;
  int ans = 0;
  
  for (int i = 0; i < H; i++){
    for (int j = 0; j < W; j++){
      cin >> s[i][j];
      if(s[i][j]=='.') ans++;
    }
  }


  if(bfs(0, 0, H, W)){
    ans -= d[H-1][W-1] + 1;
    printf("%d\n", ans);
  }else{
    printf("-1\n");
  }
  
}
