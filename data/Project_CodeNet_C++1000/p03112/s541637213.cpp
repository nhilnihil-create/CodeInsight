//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define repd(i,a,b) for (int i=(a);i<(b);i++)
#define rep(i,n) repd(i,0,n)
typedef long long ll;
typedef long double lb;
#define int long long
#define double long double
#define endn "\n"
typedef pair<int,int> P;
template<class T> inline bool chmin(T& a, T b){if(a>b){a = b;return 1;}return 0;}
template<class T> inline bool chmax(T& a, T b){if(a<b){a = b;return 1;}return 0;}
const int MOD = 1000000007;
//const int MOD = 998244353;
template<class T> inline int add(T& a, T b, T M = MOD){a=(a+M)%M;b=(b+M)%M;a=(a+b)%M;return a;};
template<class T> inline int mul(T& a, T b, T M = MOD){if(a>=M)a%=M;if(b>=M)b%=M;a*=b;if(a>=M)a%=M;return a;};
const ll INF = 1e16;
const double EPS = 1e-10;
const double PI = 3.141592653589793;
const string abc="abcdefghijklmnopqrstuvwxyz";
const string ABC="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const pair<int,int> fd[] = {make_pair(1,0),make_pair(-1,0),make_pair(0,1),make_pair(0,-1)}; 

////////////////////////////////////////////////////////////////////
///////////////////////___modpow___////////////////////
ll modpow(ll a,  ll n, const ll &MOD = MOD){
  ll ret = n == 0 ? 1 : modpow(a, n/2, MOD);
  (ret *= ret) %= MOD;
  if(n%2)((ret *= a) %= MOD);
  return ret;
}
///////////////////////___modinv___////////////////////
ll modinv(ll d, const ll &MOD = MOD){
  return modpow(d, MOD-2, MOD);
}
////////////////////////////////////////////////////////////////////

int a, b, q, s[110000], t[110000];
vector<int> query;
signed main(){
  cin>>a>>b>>q;
  rep(i,a)cin>>s[i];
  rep(i,b)cin>>t[i];
  rep(i,q){
    int x;cin>>x;query.push_back(x);
  }
  rep(i,q){
    int x = query[i];int ret = INF;
    auto sl = upper_bound(s,s+a,x);
    auto sr = lower_bound(s,s+a,x);
    auto tl = upper_bound(t,t+b,x);
    auto tr = lower_bound(t,t+b,x);
    int xx;
    if(sl != s+0){
      sl--;int sum = abs(x-(*sl));xx = *sl;
      auto l = upper_bound(t,t+b,xx);
      auto r = lower_bound(t,t+b,xx);
      if(l != t)l--;
      sum += min(abs(*l - *sl), abs(*r - *sl));
      chmin(ret, sum);
    }
    if(sr != s+a){
      int sum = abs(x-(*sr));xx = *sr;
      auto l = upper_bound(t,t+b,xx);
      auto r = lower_bound(t,t+b,xx);
      if(l != t)l--;
      sum += min(abs(*l - *sr), abs(*r - *sr));
      chmin(ret, sum);
    }
    if(tl != t+0){
      tl--;int sum = abs(x-(*tl));xx = *tl;
      auto l = upper_bound(s,s+a,xx);
      auto r = lower_bound(s,s+a,xx);
      if(l != s)l--;
      sum += min(abs(*tl - *l), abs(*tl - *r));
      chmin(ret, sum);
    }
    if(tr != t+b){
      int sum = abs(x-(*tr));xx = *tr;
      auto l = upper_bound(s,s+a,xx);
      auto r = lower_bound(s,s+a,xx);
      if(l != s)l--;
      sum += min(abs(*tr - *l), abs(*tr - *r));
      chmin(ret, sum);
    }
    cout << ret << endl;
  }
}
