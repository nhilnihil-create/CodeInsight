#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for (int i=0;i<(n);i++)
#define Graph vector<vector<int>>
#define INF 1001001001

int masu[50][50];


int main() {
  
  int H,W;
  cin >> H >> W;

  int white = 0; //白いマス目の数

  rep(i,H){
    rep(j,W){
      char a;
      cin >> a;
      if( a == '.'){
        masu[i][j]=1;
        white++;
      }
      else masu[i][j]=0;    
    }
  }

  //最短距離を求める
  int gx = W-1, gy = H-1;


  vector<vector<int>> dist(50, vector<int>(50, -1));
  queue< pair<int,int> > que;

  vector<int> dx = { 0, 1, 0, -1 };
  vector<int> dy = { 1, 0, -1, 0 };

  dist.at(0).at(0) = 1;
  que.push( make_pair(0,0) ); 

  while( !que.empty() ){
        pair<int,int> v = que.front();
        que.pop();
        int x = v.first;
        int y = v.second;

        // v から辿れる頂点をすべて調べる
        rep(i,4) {
            int nv_x = x;
            int nv_y = y;
            nv_x += dx[i];
            nv_y += dy[i];

            //通れるか？
            if( nv_x < 0 || nv_x >= W ) continue; // すでに発見済みの頂点は探索しない
            if( nv_y < 0 || nv_y >= H ) continue;
            if( masu[nv_y][nv_x] == 0 ) continue;
                            
            //もう通っているか？
            if( dist[nv_y][nv_x] != -1 ||  nv_x == 0 && nv_y == 0 ) continue;
            if(dist[gy][gx] != -1) break;

       
            // 新たな白色頂点 nv について距離情報を更新してキューに追加する
            que.push( make_pair(nv_x,nv_y) );
            dist[nv_y][nv_x] = dist[y][x] + 1;

        }
}
  
  if( dist[gy][gx] != -1 ) {
    printf("%d\n", white - dist[gy][gx]  );
    return 0;
  }
  
  
  cout << -1 << endl;
  return 0;

}
