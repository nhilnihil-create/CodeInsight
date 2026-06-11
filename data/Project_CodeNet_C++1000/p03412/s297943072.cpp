//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
using ld = long double;
template<typename T> using V = vector<T>;
template<typename T> using VV = vector<vector<T>>;
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define eb emplace_back
#define lb lower_bound
#define ub upper_bound
#define all(v) (v).begin(),(v).end()
#define siz(v) (ll)(v).size()
#define rep(i,a,n) for(ll i=a;i<(ll)(n);++i)
#define repr(i,a,n) for(ll i=n-1;(ll)a<=i;--i)
#define ENDL '\n'
typedef pair<int,int> Pi;
typedef pair<ll,ll> PL;
constexpr ll mod = 1000000007;
constexpr ll INF = 1000000099;
constexpr ll LINF = (ll)(1e18 +99);
const vector<ll> dx={-1,1,0,0},dy={0,0,-1,1};
template<typename T,typename U> inline bool chmin(T& t, const U& u){if(t>u){t=u;return 1;}return 0;}
template<typename T,typename U> inline bool chmax(T& t, const U& u){if(t<u){t=u;return 1;}return 0;}
template<typename T> inline T gcd(T a,T b){return b?gcd(b,a%b):a;}
template<typename T,typename Y> inline T mpow(T a, Y n) {
  T res = 1;
  for(;n;n>>=1) {
    if (n & 1) res = res * a;
    a = a * a;
  }
  return res;
}


signed main(){
  cin.tie(0);ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(20);
  ll n;cin>>n;
  V<ll> a(n),b(n);
  rep(i,0,n)cin>>a[i];
  rep(i,0,n)cin>>b[i];


  ll ans=0;
  rep(i,0,30){
    V<ll> u(n);
    rep(j,0,n){
      u[j]=b[j]%(1ll<<(i+1));
    }

    sort(all(u));

    ll ocnt=0;
    rep(j,0,n){
      auto l=lb(u.begin(),u.end(),(1ll<<i)-(a[j]%(1ll<<(i+1))));
      auto r=lb(u.begin(),u.end(),(1ll<<(i+1))-(a[j]%(1ll<<(i+1))));
      ocnt+=distance(l,r);

      l=lb(u.begin(),u.end(),(1ll<<i)+(1ll<<(i+1))-(a[j]%(1ll<<(i+1))));
      r=lb(u.begin(),u.end(),(1ll<<(i+2))-1-(a[j]%(1ll<<(i+1))));
      ocnt+=distance(l,r);
    }

    if(ocnt%2)ans+=(1<<i);
    //cerr<<ans<<ENDL;
  }

  cout<<ans<<ENDL;
}
//! ( . _ . ) ! 
//CHECK overflow,vector_size,what to output?