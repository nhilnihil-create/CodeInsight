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



int main(){
  int n, m;
  cin >> n >> m;
  int s[m][n];
  REP(i,m)REP(j,n) s[i][j] = 0;

  REP(i,m){
    int k;
    cin >> k;
    REP(j,k){
      int x; cin >> x;
      --x;
      s[i][x] = 1;
    }
  }
  // REP(i,m){
  //   REP(j,n){
  //     cout << s[i][j] << " ";
  //   }
  //   cout << endl;
  // }

  vector<int> p(m); //電球ONの条件
  REP(i,m) cin >> p[i];

  //デバック
  // REP(i,m){
  //   for(auto x : s[i]) cout << x << endl;
  // }
  // for(auto x: p) cout << x << endl;

  int cnt = 0;
  REP(bi, 1 << n){
    vector<int> sum(n);
    //cout << "switch" << endl;
      REP(j, n) if( bi >> j &1){
        //cout << j << " ";
        REP(i,m) if( s[i][j] == 1) sum[i]++;
      }
      bool ok = true;
      REP(i,m){
        if(sum[i]%2 !=  p[i]) ok = false;
      }
      if(ok) ++cnt;
  }

  cout << cnt << endl;

  return 0;
}
