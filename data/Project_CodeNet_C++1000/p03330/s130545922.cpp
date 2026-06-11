#include <bits/stdc++.h>
using namespace std;

using int32 = int_fast32_t;
using int64 = int_fast64_t;

const int32 INF = 1e9;
const int32 MOD = 1e9+7;
const int64 LLINF = 1e18;

#define YES(n) cout << ((n) ? "YES\n" : "NO\n"  )
#define Yes(n) cout << ((n) ? "Yes\n" : "No\n"  )
#define POSSIBLE cout << ((n) ? "POSSIBLE\n" : "IMPOSSIBLE\n"  )
#define ANS(n) cout << (n) << "\n"
#define REP(i,n) for(int64 i=0;i<(n);++i)
#define FOR(i,a,b) for(int64 i=(a);i<(b);i++)
#define FORR(i,a,b) for(int64 i=(a);i>=(b);i--)
#define ALL(obj) (obj).begin(),(obj).end()
#define pii pair<int32,int32>
#define pll pair<int64,int64>
#define pb(a) push_back(a)

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int32 n,cn;
  cin >> n >> cn;
  vector<vector<int32>> d(cn, vector<int32>(cn));
  REP(i,cn)REP(j,cn)cin >> d[i][j];
  vector<vector<int32>> c(n,vector<int32>(n));
  REP(i,n)REP(j,n){
    cin >> c[i][j];
    --c[i][j];
  }
  vector<vector<int32>> dsum(3,vector<int32>(cn,0));
  REP(nc,cn){
    REP(i,n)REP(j,n){
      dsum[(i+j)%3][nc] += d[c[i][j]][nc];
    }
  }
  int32 ans = INF;
  REP(i,cn){
    REP(j,cn){
      if(i == j)continue;
      REP(k,cn){
        if(i == k || j == k)continue;
        ans = min(ans, dsum[0][i] + dsum[1][j] + dsum[2][k]);
      }
    }
  }
  ANS(ans);
  return 0;
}