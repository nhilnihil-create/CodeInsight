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
using vtp = vector<tuple<ll,ll,ll>>;
using vb = vector<bool>;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const ll INF = 1e15;
const int MOD = 1e9+7;
const ll LINF = 1e18;



signed main()
{
  cin.tie( 0 ); ios::sync_with_stdio( false );
  ll h,w,n; cin>>h>>w>>n;
  ll sy,sx; cin>>sy>>sx; sy--,sx--;
  string s,t; cin>>s>>t;
  
  ll l=0, r=w;
  if(s[n-1]=='L') l++;
  if(s[n-1]=='R') r--;
  for(ll i=n-2; i>=0; i--){
    if(t[i]=='L') r=min(r+1,w);
    else if(t[i]=='R') l=max(l-1,0LL);
    if(s[i]=='L') l++;
    else if(s[i]=='R') r--;
    if(l>=r){
      cout<<"NO"<<endl;
      return 0;
    }
  }
  if(sx<l || r<=sx){
    cout<<"NO"<<endl;
    return 0;
  }
  
  l=0, r=h;
  if(s[n-1]=='U') l++;
  if(s[n-1]=='D') r--;
  for(ll i=n-2; i>=0; i--){
    if(t[i]=='U') r=min(r+1,h);
    else if(t[i]=='D') l=max(l-1,0LL);
    if(s[i]=='U') l++;
    else if(s[i]=='D') r--;
    if(l>=r){
      cout<<"NO"<<endl;
      return 0;
    }
  }
  if(sy<l || r<=sy){
    cout<<"NO"<<endl;
    return 0;
  }
  cout<<"YES"<<endl;
}
