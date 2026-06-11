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

ll n,m,Q;
vvll sum;

signed main()
{
  cin.tie( 0 ); ios::sync_with_stdio( false );
  cin>>n>>m>>Q;
  
  vll l(m), r(m);
  rep(i,m) cin>>l[i]>>r[i];
  
  sum=vvll(n+1, vll(n+1));
  rep(i,m){
    sum[l[i]][r[i]]++;
  }
  
  rep(i,n){
    rep(j,n){
      sum[i+1][j+1]+=sum[i+1][j]+sum[i][j+1]-sum[i][j];
    }
  }
  
  vll p(Q), q(Q);
  rep(i,Q) cin>>p[i]>>q[i];
  
  rep(i,Q){
    ll l=p[i], r=q[i];
    ll ans=sum[r][r]-sum[r][l-1]-sum[l-1][r]+sum[l-1][l-1];
    cout<<ans<<endl;
  }
  
}