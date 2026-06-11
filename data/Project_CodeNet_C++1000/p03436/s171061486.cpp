#include<iostream>
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <cstdio> // printf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset> // bitset
#include <cctype> // isupper, islower, isdigit, toupper, tolower
#include <iomanip>//setprecision
#include<math.h>
#include <functional>
#include<climits>
using namespace std;
#define ll  long long 
#define rep(i, n)        for(ll i=0; i<(ll)(n); ++i)
#define mod 1000000007
const int INF=1000000000;
const int MAX_N=55;
const int MAX_M=55;
typedef pair<int,int> P;
char maze[MAX_N][MAX_N+1];
int N,M;
int sx,sy;
int gx,gy;
int d[MAX_N][MAX_N];
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
int bfs(){
  cin>>N>>M;
  int count =0;
  sx=0;
  sy=0;
  gx=N-1;
  gy=M-1;
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      cin>>maze[i][j];
      
      /*if(maze[i][j]=='S'){
        sx=i;
        sy=j;
      }else if(maze[i][j]=='G'){
        gx=i;
        gy=j;
      }*/
      if(maze[i][j]=='.')count++;
    }
  }
  if(maze[0][0]=='#'){
    return -1;
  }
  if(maze[N-1][M-1]=='#'){
    return -1;
  }
  queue<P>que;
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      d[i][j]=INF;
    }
  }
  que.push(P(sx,sy));
  d[sx][sy]=0;
  while(que.size()){
    P p=que.front();que.pop();
    if(p.first==gx&&p.second==gy)break;
    for(int i=0;i<4;i++){
      int nx=p.first+dx[i],ny=p.second+dy[i];
      if(0<=nx&&nx<N&&0<=ny&&ny<M&&maze[nx][ny]!='#'&&d[nx][ny]==INF){
        que.push(P(nx,ny));
        d[nx][ny]=d[p.first][p.second]+1;
      }
    }
  }
  return count-(d[gx][gy]+1);
}
int main(){
  ll kotae=bfs();
  if(kotae>=0)cout<<kotae;
  else cout<<-1;
  return 0;
}