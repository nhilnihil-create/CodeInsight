#include <bits/stdc++.h>
using namespace std;

// #define int long long
#define rep(i, n) for (int i = (int)(0); i < (int)(n); ++i)
#define reps(i, n) for (int i = (int)(1); i <= (int)(n); ++i)
#define rrep(i, n) for (int i = ((int)(n)-1); i >= 0; i--)
#define rreps(i, n) for (int i = ((int)(n)); i > 0; i--)
#define irep(i, m, n) for (int i = (int)(m); i < (int)(n); ++i)
#define ireps(i, m, n) for (int i = (int)(m); i <= (int)(n); ++i)
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
#define sz(x) int(x.size())

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vs = vector<string>;
using vpll = vector<pair<ll, ll>>;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const ll INF = 1e15;
const int MOD = 1e9+7;
const ll LINF = 1e18*5;

signed main()
{
  cin.tie( 0 ); ios::sync_with_stdio( false );
  ll n,k; cin>>n>>k;
  vpll p(n);
  vll x(n), y(n);
  rep(i,n){
    ll a,b; cin>>a>>b;
    p[i]={a,b};
    x[i]=a, y[i]=b;
  }
  vsort(x);
  vsort(y);
  
  ll ans=LINF;
  rep(x1,n){
    irep(x2,x1+1,n){
      rep(y1,n){
        irep(y2,y1+1,n){
          ll cnt=0;
          rep(i,n){
            ll px=p[i].first, py=p[i].second;
            if(x[x1]<=px&&px<=x[x2] && y[y1]<=py&&py<=y[y2]){
              cnt++;
            }
          }
          if(cnt>=k){
            chmin(ans,(x[x2]-x[x1])*(y[y2]-y[y1]));
          }
        }
      }
    }
  }
  cout<<ans<<endl;
}