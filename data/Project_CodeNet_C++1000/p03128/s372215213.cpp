#include <bits/stdc++.h>
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define RFOR(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define rep(i,n) FOR(i,0,(n))
#define REPS(i,n) FOR(i,1,(n)+1)
#define RREP(i,n) RFOR(i,0,(n))
#define rng(x) (x).begin(),(x).end()
#define rrng(x) (x).rbegin(),(x).rend()
#define debug(x) cout << #x << " = " << (x) << endl;
#define SORT(x) sort(rng(x))
#define RSORT(x) sort(rrng(x))
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

const string MINF = "-";

//template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

ll gcd(ll a, ll b) { return b ? gcd(b,a%b) : a;}
ll lcm(ll a, ll b) { return a/gcd(a,b)*b;}

void chmax(string &a, string b) {
  if (a == MINF) a = b;
  else if (a.size() < b.size()) a = b;
  else if (a.size() == b.size()) {
    if (a < b) a = b;
  }
}

long long match[10] = {-1,2,5,5,4,5,6,3,7,6};
string dp[10010];

int main () {
  int n, m;
  cin >> n >> m;
  vi a(m);
  rep(i,m) cin >> a[i];

  rep(i,10010) dp[i] = MINF;
  dp[0] = "";
  rep(i,n) {
    if (dp[i] == MINF) continue;
    for (auto A : a) {
      chmax(dp[i+match[A]], dp[i] + (char)('0'+A));
    }
  }

  cout << dp[n] << endl;
  return 0;
}