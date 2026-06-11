#include<bits/stdc++.h>
using namespace std;
const long long INF = 1LL << 60;
template<class T> inline bool chmax(T& a, T b){if(a<b){a=b;return 1;}return 0;}
template<class T> inline bool chmin(T& a, T b){if(a>b){a=b;return 1;}return 0;}
#define rep(i,n) for(int i=0;i<n;i++)
#define all(a)  (a).begin(),(a).end()
//bitset<64>(x).count()
//fixed << setprecision(15) << 
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};
int main (){
  int r, c, sy, sx, gy, gx, ans=0;
  cin >> r >> c ;
  
  bool a[r+2][c+2] = {false};
  int dist[r+2][c+2] ;
  rep(i, r+2){
    rep(j, c+2){
      dist[i][j] = -1;
      a[i][j] = 0;
    }
  }
  char ca;
  rep(i, r){
    rep(j, c){
      cin >> ca;
      if(ca=='#'){
        a[i+1][j+1] = 0;
      } else{
        a[i+1][j+1] = 1;
        ans++;
      }
    }
  }
  sy =1;
  sx =1;
  gy =r;
  gx =c;
  queue<pair<int, int> > que;
  pair<int, int> pa;
  pa.first = sy;
  pa.second = sx;
  que.push(pa);
  dist[pa.first][pa.second] = 0;
  while(que.size()){
    pair<int, int> tmp;
    tmp = que.front();
    que.pop();
    rep(i, 4){
      pair<int, int> pre;
      pre.first = tmp.first +dx[i];
      pre.second = tmp.second +dy[i];
      if(dist[tmp.first +dx[i]][tmp.second +dy[i]]==-1&&a[tmp.first +dx[i]][tmp.second +dy[i]]==1){
        dist[tmp.first +dx[i]][tmp.second +dy[i]] = dist[tmp.first][tmp.second]+1;       
        que.push(pre);
      }
    }
  }
  if(dist[gy][gx]==-1)
    cout << -1 << endl;
  else
    cout << ans - dist[gy][gx] - 1<< endl;
}
