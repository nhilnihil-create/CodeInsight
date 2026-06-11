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
#define rep(i,a,n) for(ll i=a;i<(ll)(n);i++)
#define repr(i,a,n) for(ll i=n-1;(ll)a<=i;i--)
#define lb lower_bound
#define ub upper_bound
typedef pair<int,int> P;
typedef pair<ll,ll> PL;
const ll mod = 1000000007;
const ll INF = 1000000099;
const ll LINF = (ll)(1e18 +99);
vector<ll> dx={-1,1,0,0},dy={0,0,-1,1};
template<typename T,typename U> void chmin(T& t, const U& u){if(t>u)t=u;}
template<typename T,typename U> void chmax(T& t, const U& u){if(t<u)t=u;}
template<typename T>T gcd(T a,T b){return b?gcd(b,a%b):a;}
template<typename T>T mpow(T a, T n) {
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
  ll n,ans=0;cin>>n;
  string s;cin>>s;
  map<pair<string,string>,ll> ma;
  rep(i,0,mpow(2ll,n)){
      string a="",b="";
      int x=i,cnt=0;
      rep(j,0,n){
          if(x&1){
              a+=s[n+cnt];
          }else{
              b+=s[n+cnt];
          }
          cnt++;
          x/=2;
      }
      reverse(all(b));
      ma[mp(a,b)]++;
  }

  rep(i,0,mpow(2ll,n)){
      string a="",b="";
      int x=i,cnt=0;
      rep(j,0,n){
          if(x&1){
              a+=s[cnt];
          }else{
              b+=s[cnt];
          }
          cnt++;
          x/=2;
      }
      reverse(all(b));
      ans+=ma[mp(b,a)];
  }
  cout<<ans<<endl;
}
//( ・ __ ・ ) KEEP BEING ORGANIZED
//CHECK overflow,vector_size,what to output?