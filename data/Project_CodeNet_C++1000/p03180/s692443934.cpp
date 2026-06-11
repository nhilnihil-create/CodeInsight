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
#define all(v) (v).begin(),(v).end()
#define siz(v) (ll)(v).size()
#define rep(i,a,n) for(ll i=a;i<(ll)(n);++i)
#define repr(i,a,n) for(ll i=n-1;(ll)a<=i;--i)
#define lb lower_bound
#define ub upper_bound
#define ENDL '\n'
typedef pair<int,int> Pi;
typedef pair<ll,ll> PL;
const ll mod = 1000000007;
const ll INF = 1000000099;
const ll LINF = (ll)(1e18 +99);
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

ll dp[1<<17]={};
ll cost[1<<17]={};

signed main(){
  cin.tie(0);ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(20);
  int n;cin>>n;
  VV<ll> v(n,V<ll>(n));
  rep(i,0,n)rep(j,0,n)cin>>v[i][j];

  rep(i,0,1<<n){
    rep(j,0,n){
      rep(k,j+1,n){
        if((i&(1<<j)) && (i&(1<<k))){
          cost[i]+=v[j][k];
        }
      }
    }
    dp[i]=cost[i];
  }

  rep(i,0,1<<n){
    for(int j=i;j>0;--j,j&=i){
      chmax(dp[i],dp[j]+dp[i^j]);
    }   
  }

  cout<<dp[(1<<n)-1]<<ENDL;


}
//( ・ __ ・ ) KEEP BEING ORGANIZED
//CHECK overflow,vector_size,what to output?