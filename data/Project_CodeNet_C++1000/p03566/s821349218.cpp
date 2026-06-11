#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(c) (c).begin(),(c).end()
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
#define MINF(a) memset(a,0x3f,sizeof(a))
#define POW(n) (1LL<<(n))
#define IN(i,a,b) (a <= i && i <= b)
using namespace std;
template <typename T> inline bool CHMIN(T& a,T b) { if(a>b) { a=b; return 1; } return 0; }
template <typename T> inline bool CHMAX(T& a,T b) { if(a<b) { a=b; return 1; } return 0; }
template <typename T> inline void SORT(T& a) { sort(ALL(a)); }
template <typename T> inline void REV(T& a) { reverse(ALL(a)); }
template <typename T> inline void UNI(T& a) { sort(ALL(a)); a.erase(unique(ALL(a)),a.end()); }
const int MOD = 1000000007;
const int INF = 0x3f3f3f3f3f3f3f3f;
const double EPS = 1e-10;
/* ---------------------------------------------------------------------------------------------------- */

int N;
int t[110],v[110];
int vl[40010],vr[40010];
double dp[40010][210];

signed main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  cout << fixed << setprecision(10);

  cin >> N;
  REP(i,N) cin >> t[i], t[i] *= 2;
  REP(i,N) cin >> v[i], v[i] *= 2;
  int c = 0;
  vl[c] = 0;
  REP(i,N) {
    vr[c++] = v[i];
    REP(j,t[i]-1) {
      vl[c] = vr[c] = v[i];
      c++;
    }
    vl[c] = v[i];
  }
  vr[c] = 0;

  fill_n((double*)dp,40010*110,-INF);
  dp[0][0] = 0;
  REP(i,c) REP(j,210) if (dp[i][j] != -INF) {
    if (j <= vl[i+1] && j <= vr[i+1]) CHMAX(dp[i+1][j],dp[i][j]+j);
    if (j+1 <= vl[i+1] && j+1 <= vr[i+1]) CHMAX(dp[i+1][j+1],dp[i][j]+j+0.5);
    if (0 <= j-1 && j-1 <= vl[i+1] && j-1 <= vr[i+1]) CHMAX(dp[i+1][j-1],dp[i][j]+j-0.5);
  }
  cout << dp[c][0]/4 << endl;

  return 0;
}