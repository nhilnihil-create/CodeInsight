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



signed main(){
  cin.tie(0);ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(20);
  ll n,num=0;cin>>n;
  VV<PL> e(20,V<PL>(0));

  ll cnt=0,msb=0;
  if((1<<19)&n){
    cnt=1<<19;
    msb=19;
  }

  repr(i,0,19){
    if((1<<i)& n){
      chmax(msb,i);
      if(cnt){
        e[0].eb(19-i,cnt);
        ++num;
      }
      cnt+=1<<i;
    }
  }

  rep(i,0,19){
    if(18-i<msb){
      e[i].eb(i+1,1<<(18-i));
      ++num;
    }
    e[i].eb(i+1,0);
    ++num;
  }


  cout<<20<<" "<<num<<ENDL;
  rep(i,0,20)rep(j,0,siz(e[i])){
    cout<<i+1<<" "<<1+e[i][j].fs<<" "<<e[i][j].sc<<ENDL;
  }
}
//( ・ __ ・ ) KEEP BEING ORGANIZED
//CHECK overflow,vector_size,what to output?