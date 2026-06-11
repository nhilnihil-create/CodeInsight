#include<bits/stdc++.h>
using namespace std ;
typedef pair<int, int> P ;

int board[60][60] ;
int d[60][60] ;
queue<P> que ;
int pre = 0 ;
int H , W ;
const int INF = 100000000 ;
int dx[4] = {-1,1,0,0} , dy[4]= {0,0,-1,1} ;

int bfs() {
  int sx = 0 , sy = 0 ;
  int gx = H - 1 , gy = W - 1 ;
  que.push(P(sx,sy)) ;
  d[sx][sy] = 0 ;
  
  while(que.size()){
    P p = que.front() ; que.pop() ;
    if(p.first == gx && p.second == gy ) break ;
    
    for(int i = 0 ; i < 4 ; i++ ){
      int nx = p.first + dx[i] , ny = p.second + dy[i] ;
      if(nx >= 0 && ny >= 0 && nx < H && ny < W && d[nx][ny] == INF && board[nx][ny] == 0 ){
        d[nx][ny] = d[p.first][p.second] + 1 ;
        que.push(P(nx,ny)) ;
      }
    }
  }
  return d[gx][gy] ;
}

int main () {
  //入力
  cin >> H >> W ;
  for(int i = 0 ; i < H ; i++ ){
    for(int j = 0 ; j < W ; j++ ){
      char ch ;
      cin >> ch ;
      if(ch == '#') board[i][j] = 1 ;
      else {
        board[i][j] = 0 ;
        pre ++ ;
      }
    }
  }
  
  //演算
  for(int i = 0 ; i < H ; i++ )
    for(int j = 0 ; j < W ; j++ )
      d[i][j] = INF ;
  int ans = bfs() ;
  if(ans != INF )cout << pre - ( ans + 1 ) << endl ;
  else cout << -1 << endl ;
}
