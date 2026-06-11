#include <bits/stdc++.h>
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define rep(i,n) for (int i = (0); i < (n); ++i)
#define rng(x) (x).begin(),(x).end()
#define rrng(x) (x).rbegin(),(x).rend()
#define debug(x) cout << #x << " = " << (x) << endl;
#define SUM(x) accumulate(rng(x),0)
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define sz(x) (int)(x).size()
#define bn(x) ((1<<x)-1)
#define dup(x,y) (((x)+(y)-1)/(y))
#define uni(x) x.erase(unique(rng(x)),x.end())
#define SP << " " <<
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int mod = 1000000007;
const double EPS = 1e-9;
const int INF = 1<<30;
const ll INFLL = 1LL<<60;
const int dx[4] = {1,0,-1,0};
const int dy[4] = {0,1,0,-1};
//cout << fixed << setprecision(10);

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

int main () {
  string s;
  cin >> s;

  int ans = INF;
  // iは最初に使う色(0 or 1)
  rep(i,2) {
    // iを最初に使ったときに変えなければならないタイルの数
    int cnt = 0;
    rep(j,s.size()) {
      // (j%2,i) = (0,0), (1,1)のときtrue
      if ((j%2 == 0) ^ (s[j] == (char)(i+'0'))) cnt++;
    }
    ans = min(ans, cnt);
  }
  cout << ans << endl;
  return 0;
}
