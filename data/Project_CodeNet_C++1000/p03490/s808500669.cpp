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

string s;
int x,y;

bool check(int s, int t, vector<int> v, bool isX = true) {
  vector<vector<bool>> dp(2,vector<bool>(16010,false));
  int cur = 0, nxt = 1;
  dp[cur][s+8000] = true;
  REP(i,v.size()) {
    fill(ALL(dp[nxt]),false);
    REP(j,16010) if (dp[cur][j]) {
      if (i == 0 && isX) {
        dp[nxt][j+v[i]] = true;
      } else {
        dp[nxt][j-v[i]] = dp[nxt][j+v[i]] = true;
      }
    }
    swap(cur,nxt);
  }
  return dp[cur][t+8000];
}

signed main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  cout << fixed << setprecision(10);

  cin >> s >> x >> y;
  s += "T";
  vector<int> v[2];
  int p = 0, c = 0;
  REP(i,s.size()) {
    if (s[i] == 'T') {
      v[p].push_back(c);
      c = 0;
      p ^= 1;
    } else {
      c++;
    }
  }
  cout << (check(0,x,v[0]) && check(0,y,v[1],false) ? "Yes" : "No") << endl;

  return 0;
}