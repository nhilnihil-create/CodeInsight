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

template<typename T>
struct BIT {
  int n;
  vector<T> d;
  BIT(int n=0):n(n),d(n+1) {}
  void add(int i, T x=1) {
    for (; i <= n; i += i&-i) {
      d[i] += x;
    }
  }
  T sum(int i) {
    T x = 0;
    for (; i; i -= i&-i) {
      x += d[i];
    }
    return x;
  }
  T sum(int l, int r) {
    return sum(r-1) - sum(l-1);
  }
};

ll n;
vll a;

bool isOk(ll mid){
  vll s(n+1);
  rep(i,n){
    s[i+1]=s[i];
    if(a[i]<=mid) s[i+1]++;
    else s[i+1]--;
  }
  
  BIT<ll> bit(2*n+10);
  ll cnt=0;
  rep(i,n+1){
    cnt+=bit.sum(s[i]+n+1-1);
    bit.add(s[i]+n+1);
  }
  return cnt>n*(n+1)/2/2;
}

signed main()
{
  cin.tie( 0 ); ios::sync_with_stdio( false );
  cin>>n;
  a.resize(n);
  rep(i,n) cin>>a[i];
  
  ll ok=1e9, ng=0;
  while(abs(ok-ng)>1){
    ll mid=(ok+ng)/2;
    if(isOk(mid)) ok=mid;
    else ng=mid;
  }
  cout<<ok<<endl;
}