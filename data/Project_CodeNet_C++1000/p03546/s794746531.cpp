#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define REP2(i,x,n) for (int i = x; i <(n); ++i)
#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()
using namespace std;
using ll = long long;
using P = pair<int,int>;
static const double PI = acos(-1);
static const int INF = 1e9+7;

static const int MAX = 100;
static const long long INFTY = (1LL<<32);

int n;
long long d[MAX][MAX];  //d[i][j]の最短コストを記録するDPテーブル

void floyd() {

  for( int k = 0; k < n; k++){         //経由する頂点数
    for(int i = 0; i < n; i++){         //始点
      if( d[i][k] == INFTY ) continue;

      for(int j = 0; j < n; j++){       //終点
        if( d[k][j] == INFTY ) continue;
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
        //i -> j   i -> k -> j //iからｊへの最短経路を示す

      }
    }
  }
}


int main(){
  int H, W;
  cin >> H >> W;

  n = 10;


  REP(i,n)REP(j,n) cin >> d[i][j];
  floyd();


  //int field[H][W];

  ll ans = 0;
  REP(h,H)REP(w,W){
    int a;
    cin >> a;
    if(a == -1) continue;
    ans += d[a][1];
  }

  cout << ans << endl;


  return 0;
}
