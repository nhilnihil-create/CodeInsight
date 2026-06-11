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

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

ll n,q;
string s;
vector<char> t,d;

bool isOkL(ll mid){
  ll pos=mid;
  rep(i,q){
    if(s[pos]==t[i]){
      if(d[i]=='L'){
        pos--;
        if(pos<0) return true;
      }else{
        pos++;
        if(pos>=n) return false;
      }
    }
  }
  return false;
}

bool isOkR(ll mid){
  ll pos=mid;
  rep(i,q){
    if(s[pos]==t[i]){
      if(d[i]=='R'){
        pos++;
        if(pos>=n) return true;
      }else{
        pos--;
        if(pos<0) return false;
      }
    }
  }
  return false;
}

signed main()
{
  cin.tie( 0 ); ios::sync_with_stdio( false );
  cin>>n>>q>>s;
  t.resize(q), d.resize(q);
  rep(i,q) cin>>t[i]>>d[i];
  
  ll ans=0;
  ll ok=-1, ng=n+1;
  while(abs(ok-ng)>1){
    ll m=(ok+ng)/2;
    if(isOkL(m)) ok=m;
    else ng=m;
  }
  ans=ok+1;
  
  ok=n, ng=-1;
  while(abs(ok-ng)>1){
    ll m=(ok+ng)/2;
    if(isOkR(m)) ok=m;
    else ng=m;
  }
  ans+=n-ok;
  ans=n-ans;
  chmin(ans,n);
  cout<<ans<<endl;
}
