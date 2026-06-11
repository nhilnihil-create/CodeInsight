#include<bits/stdc++.h>
using namespace std;
#define FOR(i,r,n) for(ll i=(ll)(r);i<(ll)(n);++i)
#define RFOR(i,r,n) for(ll i=(ll)(n-1);i>=r;--i)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) RFOR(i,0,n)
#define ALL(x) x.begin(),x.end()
#define RALL(x) x.rbegin(),x.rend()
#define SORT(c) sort(ALL((c)))
#define RSORT(c) sort(RALL((c)))
#define PB(n) push_back(n)
#define endl '\n'
#define DOUT(x) cout << #x << " = " << (x) << endl
#define IN(n) cin >> n
#define IN2(a,b) cin >> a >> b
#define IN3(a,b,c) cin >> a >> b >> c
#define VIN(V) for(ll ii = 0; ii < (ll)(V).size(); ii++) {cin >> (V).at(ii);}
#define OUT(n) cout << n << endl
#define OUT2(n1,n2) cout << n1 << " " << n2 << endl
#define OUT3(n1,n2,n3) cout << n1 << " " << n2 << " " << n3 << endl
#define VOUT(V) REP(ii,(V).size()){cout << (V)[ii] << " ";} cout<<endl;
#define VOUT2(V) REP(jj,(V).size()){VOUT(V[jj])}
typedef long long int ll;
typedef vector<ll> vi;
typedef vector<vi > vvi;
typedef vector<pair<ll, ll> > vp;
typedef vector<string> vs;
typedef vector<char> vc;
typedef list<ll> lst;
typedef pair<ll, ll> P;
const long long INF = numeric_limits<ll>::max();
constexpr long long MOD = 1000000007;
constexpr long double PI = 3.1415926;
template <class T> T &chmin(T &a, const T &b) { return a = min(a, b); }
template <class T> T &chmax(T &a, const T &b) { return a = max(a, b); }
ll n, m, k, ans, sum, cnt = 0; string s; char c; bool flg;

int main(){
  cin.tie(0);ios::sync_with_stdio(false);
  // cout << fixed << setprecision(numeric_limits<double>::max_digits10);
  ll a,b;
  IN3(n,a,b);

  FOR(i,1,n+1) {
    ll sum = 0;
    sum += i / 10000;
    sum += (i % 10000) / 1000;
    sum += (i % 1000) / 100;
    sum += (i % 100) / 10;
    sum += i % 10;
    if (a <= sum && sum <= b) {
      // OUT2(i, sum);
      ans += i;
    }
  }
  OUT(ans);
}
