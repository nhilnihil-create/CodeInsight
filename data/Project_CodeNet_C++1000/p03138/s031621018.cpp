#include <bits/stdc++.h>
using namespace std;

// #define int long long
#define rep(i, n) for (long long i = (long long)(0); i < (long long)(n); ++i)
#define reps(i, n) for (long long i = (long long)(1); i <= (long long)(n); ++i)
#define rrep(i, n) for (long long i = ((long long)(n)-1); i >= 0; i--)
#define rreps(i, n) for (long long i = ((long long)(n)); i > 0; i--)
#define irep(i, m, n) for (long long i = (long long)(m); i < (long long)(n); ++i)
#define ireps(i, m, n) for (long long i = (long long)(m); i <= (long long)(n); ++i)
#define SORT(v, n) sort(v, v + n);
#define REVERSE(v, n) reverse(v, v+n);
#define vsort(v) sort(v.begin(), v.end());
#define all(v) v.begin(), v.end()
#define mp(n, m) make_pair(n, m);
#define cout(d) cout<<d<<endl;
#define coutd(d) cout<<std::setprecision(10)<<d<<endl;
#define cinline(n) getline(cin,n);
#define replace_all(s, b, a) replace(s.begin(),s.end(), b, a);
#define PI (acos(-1))
#define FILL(v, n, x) fill(v, v + n, x);
#define sz(x) long long(x.size())

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vs = vector<string>;
using vpll = vector<pair<ll, ll>>;
using vtp = vector<tuple<ll,ll,ll>>;
using vb = vector<bool>;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const ll INF = 1e9;
const ll MOD = 1e9+7;
const ll LINF = 1e18;

ll dp[45][2]; // i桁目までで、k以下であるかがjという状態の

signed main()
{
  cin.tie( 0 ); ios::sync_with_stdio( false );
  
  ll n,k; cin>>n>>k;
  vll a(n);
  rep(i,n) cin>>a[i];
  
  memset(dp,-1,sizeof(dp));
  dp[41][0]=0;
  
  for(ll i=40; i>=0; i--) rep(j,2){
    ll now=k>>i&1;
    rep(nxt,2){
      if(now<nxt && j==0) continue;
      if(dp[i+1][j]==-1) continue;
      ll nj=j|(nxt<now);
      ll sum=0;
      rep(l,n){
        if((a[l]>>i&1)==0 && nxt==1) sum++;
        if((a[l]>>i&1)==1 && nxt==0) sum++;
      }
      chmax(dp[i][nj],dp[i+1][j]+(sum<<i));
    }
  }
  
  ll ans=max(dp[0][0],dp[0][1]);
  cout<<ans<<endl;
  
}