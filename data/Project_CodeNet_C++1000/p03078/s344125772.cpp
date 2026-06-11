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

const ll INF = 1e9+10;
const ll MOD = 1e9+7;
const ll LINF = 1e18;



signed main()
{
  cin.tie( 0 ); ios::sync_with_stdio( false );
  
  ll x,y,z,k; cin>>x>>y>>z>>k;
  vll a(x) , b(y), c(z);
  rep(i,x) cin>>a[i];
  rep(i,y) cin>>b[i];
  rep(i,z) cin>>c[i];
  
  vll ab, bc, ca;
  rep(i,x) rep(j,y) ab.push_back(a[i]+b[j]);
  rep(i,y) rep(j,z) bc.push_back(b[i]+c[j]);
  rep(i,z) rep(j,x) ca.push_back(c[i]+a[j]);
  
  sort(ab.rbegin(),ab.rend());
  sort(bc.rbegin(),bc.rend());
  sort(ca.rbegin(),ca.rend());
  
  // 合計値、自分、自分の値、自分以外の次のカーソル
  priority_queue<tuple<ll,ll,ll,ll>> q;
  rep(i,x) {
    q.push(tuple<ll,ll,ll,ll>(a[i]+bc[0], 0, a[i], 0));
  }
  rep(i,y) {
    q.push(tuple<ll,ll,ll,ll>(b[i]+ca[0], 1, b[i], 0));
  }
  rep(i,z) {
    q.push(tuple<ll,ll,ll,ll>(c[i]+ab[0], 2, c[i], 0));
  }
  
  ll cnt=0;
  vll ans;
  while(!q.empty() && cnt<=k*3){
    ll sum, self, point, pos;
    tie(sum,self,point,pos)=q.top(); q.pop();
    // cout<<sum<<' '<<self<<' '<<point<<' '<<pos<<endl;
    
    ans.push_back(sum);
    cnt++;
    if(self==0){
      if(pos+1<bc.size()){
        q.push(tuple<ll,ll,ll,ll>(point+bc[pos+1], self, point, pos+1));
      }
    }
    if(self==1){
      if(pos+1<ca.size()){
        q.push(tuple<ll,ll,ll,ll>(point+ca[pos+1], self, point, pos+1));
      }
    }
    if(self==2){
      if(pos+1<ab.size()){
        q.push(tuple<ll,ll,ll,ll>(point+ab[pos+1], self, point, pos+1));
      }
    }
  }
  
  rep(i,k*3){
    if(i%3==0) cout<<ans[i]<<endl;
  }
  
}