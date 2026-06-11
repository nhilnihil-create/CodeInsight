#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<functional>
#include<assert.h>
#include<numeric>
using namespace std;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
using ll = long long;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;
#define pai 3.141592653589793238462643383279

int main(){
  int H, W; cin >> H >> W; string a[H];
  rep(i, H){
    cin >> a[i];
  }
  queue<pair<int, int>>Q;
  Q.push({0, 0}); int dist[H][W] = {};
  rep(i, H){
    rep(j, W){
      if(i!=0 || j!=0) dist[i][j] = -1;
      else dist[i][j]=1;
    }
  }
  while(!Q.empty()){
      int next[5] = {0, 1, 0, -1, 0};
      auto p = Q.front(); Q.pop();
      int f = p.first; int s = p.second;
      rep(ii, 4){
        int x = f+next[ii]; int y = s+next[ii+1];
        if(x<0 || y<0 || x>=H || y>=W || a[x][y]=='#' || dist[x][y]>0) continue;
        Q.push({x, y}); dist[x][y]=dist[f][s]+1;
      }
  }
  int kuro=0;
  rep(i, H){
    rep(j, W){
      if(a[i][j]=='#') kuro++;
    }
  }
  if(dist[H-1][W-1]==-1){
    cout << -1 << endl; return 0;
  }
  cout << H*W - dist[H-1][W-1] - kuro << endl;
}
  