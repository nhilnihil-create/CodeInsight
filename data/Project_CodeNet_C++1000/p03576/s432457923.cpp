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


signed main()
{
  cin.tie( 0 ); ios::sync_with_stdio( false );
  ll n,m; cin>>n>>m;
  vpll xy(n);
  vll xs(n), ys(n);
  rep(i,n){
    ll x,y; cin>>x>>y;
    xy[i]={x,y};
    xs[i]=x, ys[i]=y;
  }
  vsort(xs);
  vsort(ys);
  
  ll ans=5*LINF;
  rep(i,n){
    irep(j,i+1,n){
      rep(k,n){
        irep(l,k+1,n){
          ll cnt=0;
          rep(ki,n){
            ll x=xy[ki].first, y=xy[ki].second;
            if(xs[i]<=x&&x<=xs[j] && ys[k]<=y&&y<=ys[l]) cnt++;
          }
          if(cnt>=m){
            ll s=(xs[j]-xs[i])*(ys[l]-ys[k]);
            if(chmin(ans,s)){
              // cout<<xs[i] <<" "<<xs[j] <<" "<< ys[k] <<" "<< ys[l] <<endl;
            }
          }
        }
      }
    }
  }
  cout<<ans<<endl;
}