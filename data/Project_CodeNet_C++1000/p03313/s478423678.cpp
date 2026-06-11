// warm heart, wagging tail,and a smile just for you!
//
//                            ▒█████▒▒
//                             ██████████▒
//                             ▒████████████▒
//                            ██████████████████
//                           ████████████████████▒
//                          ▒██████████████████████▒
//                          ▒███████████████████████
//                      ▒████▒▒▒▒▒▒█████████████████▒
//                    ███▒▒▒▒▒▒██████████████████████▒▒▒
//                  ▒██▒▒███████████████████████▒▒▒▒▒██████
//                 ▒█████████████████████████▒▒▒▒▒▒█████████▒
//                 ▒█████████████████████▒▒▒▒▒▒██████████████
//                  ▒████         ████▒▒▒▒▒████         ████▒
//              ▒█████▒    ████    ▒▒▒▒███████    ████    ██████▒
//            ▒██▒▒▒▒▒    ██████    █████████    ██████    ██▒▒▒██▒
//           █████████   ████████   █████████   ████████   ▒▒▒▒█████
//          ▒█████████    ██████    ████████▒    ██████    █████████
//          ▒██████████    ████    █████▒▒▒▒▒▒    ████    ██████████
//           ████████████        ▒▒▒▒▒▒▒████████        ███████████▒
//       ▒██████████▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒███████████████████████████████████▒
//     ███▒▒▒▒▒▒▒▒▒▒▒▒█████████████████████████████████████████▒▒████████▒
//   ▒▒▒▒▒▒▒▒▒██████████████                         ███████▒▒▒▒███████████
//   █████████████████████████                     ███████▒▒▒██████████████▒
//   █████████████████████████████             ███████▒▒▒██████████████████▒
//   ██████████████████████████████████████████████████████████████████████
//    ██████████████████████████████████████████████████████████████████▒
//      ▒█████████████████▒▒▒▒▒▒▒██████████████████████████████████▒▒▒
//
#include "bits/stdc++.h"
using namespace std;
#define MOD 1000000007
//#define MOD 998244353
const double EPS = 1e-9;
#define INF (1LL<<60)
#define D double
#define fs first
#define sc second
#define int long long
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define RFOR(i,a,b) for(int i = (b-1);i>=(a);--i)
#define REP(i,n)  FOR(i,0,(n))
#define RREP(i,n) RFOR(i,0,(n))
#define ITR(itr,mp) for(auto itr = (mp).begin(); itr != (mp).end(); ++itr)
#define RITR(itr,mp) for(auto itr = (mp).rbegin(); itr != (mp).rend(); ++itr)
#define range(i,a,b) ((a)<=(i) && (i)<(b))
#define debug(x)  cout << #x << " = " << (x) << endl;
#define SP << " " << 
typedef pair<int,int> P;
typedef vector<int> vec;
typedef vector<vector<int>> mat;

const int N = 1<<18;
mat dp(N,vec(2,0));

void solve(int x, int y){
  vec a = {dp[x][0],dp[x][1],dp[y][0],dp[y][1]};
  sort(a.rbegin(),a.rend());
  a.resize(2);
  dp[y] = a;
}

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  vector<int> a(1<<n);
  REP(i,1<<n) cin >> a[i], dp[i][0] = a[i];
  
  REP(i,n){
    REP(j,1<<n){
      if(j&(1<<i)) continue;
      solve(j,j|(1<<i));
    }
  }

  int mx = 0;
  FOR(i,1,1<<n){
    mx = max(mx,dp[i][0]+dp[i][1]);
    cout << mx << "\n";
  }

  return 0;
}