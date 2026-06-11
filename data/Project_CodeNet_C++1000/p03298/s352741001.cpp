#include <bits/stdc++.h>
#define int long long
#define uint unsigned int
#define pii pair<int, int>
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FORR(i,a,b) for(int i=(a);i>=(b);--i)
#define REP(i,n) FOR(i,0,n)
#define REPR(i,n) FORR(i,n,0)
#define ALL(c) (c).begin(),(c).end()
#define PB(a) push_back(a)
#define EMPB(...) emplace_back(__VA_ARGS__)
#define EMP(...) emplace(__VA_ARGS__)
#define MP(a,b) make_pair(a,b)
#define MT(...) make_tuple(__VA_ARGS__)
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
#define MINF(a) memset(a,0x3f,sizeof(a))
#define PW(n) (1LL<<(n))
using namespace std;
template <class T> inline bool CHMIN(T& a, T b) { if(a>b) { a=b; return 1; } return 0; }
template <class T> inline bool CHMAX(T& a, T b) { if(a<b) { a=b; return 1; } return 0; }
template <class T> inline void SORT(T& a) { sort(ALL(a)); }
template <class T> inline void REV(T& a) { reverse(ALL(a)); }
template <class T> inline void UNI(T& a) { SORT(a); a.erase(unique(ALL(a)),a.end()); }
template <class S, class T> ostream& operator<<(ostream& os, const pair<S,T> a) {
  return os << a.first << ' ' << a.second;
}
const int MOD = 1000000007;
const int INF = 0x3f3f3f3f3f3f3f3f;
const double EPS = 1e-10;
/* ---------------------------------------------------------------------------------------------------- */

int N;
string S;
map<pair<string,string>,int> mp1,mp2;

signed main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  cout << fixed << setprecision(10);

  cin >> N >> S;
  string S1 = S.substr(0,N);
  string S2 = S.substr(N,N);
  REV(S2);
  REP(ms,PW(N)) {
    string s,t;
    REP(i,N) {
      if (ms & PW(i)) s += S1[i];
      else t += S1[i];
    }
    mp1[MP(s,t)]++;
  }
  REP(ms,PW(N)) {
    string s,t;
    REP(i,N) {
      if (ms & PW(i)) s += S2[i];
      else t += S2[i];
    }
    mp2[MP(s,t)]++;
  }
  int ans = 0;
  for (auto p : mp1) {
    ans += p.second*mp2[p.first];
  }
  cout << ans << endl;

  return 0;
}