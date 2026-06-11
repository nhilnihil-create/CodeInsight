#include <bits/stdc++.h>

#define rep(i, n) for(int i=0; i < n; i++)
#define REP(i, n, m) for(int i=n; i < m; i++)
#define reps(i, n) for(int i=1; i <= n; i++)
#define ALL(v) v.begin(), v.end()
#define rALL(v) v.rbegin(), v.rend()
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)

using namespace std;
using ll=long long;

ll mod=2019;

const ll INF = 1LL << 60;

template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}

// a^n mod を計算 再帰
ll modpow(ll a,ll n,ll &mod){
  if(!n) return 1;
  ll x = modpow(a,n/2,mod)%mod;
  x *=x;
  if(n%2==1)x*=a;
  return x%mod;
}



int main(){
  int a,b,c,k;
  cin>>a>>b>>c>>k;
  vector<int> p;
  p.pb(a);
  p.pb(b);
  p.pb(c);
  sort(ALL(p));
  rep(i,k)p[2]*=2;
  cout<<p[0]+p[1]+p[2];
}
