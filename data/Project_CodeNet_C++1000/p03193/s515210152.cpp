#include <bits/stdc++.h>
#define all(a) (a).begin(),(a).end()
#define rep(i,n) for(ll i=0,i##_len=(n);i<i##_len;i++)
#define rep2(i,a,b) for(ll i=(a),i##_len=(b);i<=i##_len;i++)
#define rrep(i,n) ll i=(n);ll now=-1;while(i--&&(now++||1))
#define Yes(n) cout<<((n)?Yes:No)
#define pb push_back
using namespace std;
using ll = long long;
using vll = vector<ll>;
using vbl = vector<bool>;
using vint = vector<int>;
using vstr = vector<string>;
static inline void ignore_ret(int x) {x++;}
template<class T> inline bool chmax(T&a,const T&b){if(a<b){a=b;return true;}return false;}
template<class T> inline bool chmin(T&a,const T&b){if(a>b){a=b;return true;}return false;}
template<class T> inline T gcd_vec(vector<T>v){T r=v.at(0);for(T i=1;i<v.size();i++)r=gcd(r,v.at(i));return r;}
template<class T> inline T lcm_vec(vector<T>v){T r=v.at(0);for(T i=1;i<v.size();i++)r=lcm(r,v.at(i));return r;}
template<class T> inline T factorial(T n){if(n==0)return 1;T r=1;for(T i=2;i<=n;i++)r*=i;return r;}
template<class T> inline T nCr(T n,T k){if(n<k||n<0||k<0)return 0;T r=1;k=min(k,n-k);for(T i=n-k+1;i<=n;i++)r*=i;return r/factorial(k);}
template<class T> inline T dot_product(vector<T>u,vector<T>v){T r=0;for(T i=0;i<u.size();i++)r+=u.at(i)*v.at(i);return r;}
template<class T> inline T sum(vector<T>v){return reduce(all(v),0LL);}

void solve(ll N, ll H, ll W, vector<ll> A, vector<ll> B) {
  int cnt = 0;
  rep(i, N) if (A.at(i) >= H && B.at(i) >= W) cnt++;
  cout << cnt << endl;
}

int main() {
  ll N;
  ignore_ret(scanf("%lld",&N));
  ll H;
  ignore_ret(scanf("%lld",&H));
  ll W;
  ignore_ret(scanf("%lld",&W));
  vector<ll> A(N);
  vector<ll> B(N);
  for(int i = 0 ; i < N ; i++){
    ignore_ret(scanf("%lld",&A[i]));
    ignore_ret(scanf("%lld",&B[i]));
  }
  solve(N, H, W, move(A), move(B));
  return 0;
}
