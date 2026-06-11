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

template<typename T,typename Y>
ostream& operator<<(ostream& os,const pair<T,Y>& p){
   return os<<"{"<<p.fs<<","<<p.sc<<"}";
}
template<typename T> ostream& operator<<(ostream& os,const V<T>& v){
   os<<"{";
  for(auto e:v)os<<e<<",";
  return os<<"}";
}
template<typename ...Args>
void debug(Args&... args){
  for(auto const& x:{args...}){
    cerr<<x<<' ';
  }
  cerr<<ENDL;
}



signed main(){
  cin.tie(0);ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(20);
  ll n;cin>>n;
  V<ll> v(n);rep(i,0,n)cin>>v[i];

  ll ng=-1,ok=200010,mid,len,tmpnum,tmptype;

  while(abs(ok-ng)>1){
    mid=(ok+ng)/2;

    stack<ll> num,type;
    len=0;

    rep(i,0,n){
      if(len<v[i]){
        if(type.size() && type.top()==0){
          num.top()+=v[i]-len;
        }else{
          num.push(v[i]-len);
          type.push(0);
        }
        len=v[i];
      }else{
        while(v[i]<=len-num.top()){
          len-=num.top();
          num.pop();
          type.pop();
        }
        num.top()-=len-v[i];
        len=v[i];

        if(mid==type.top()){
          tmpnum=num.top(); num.pop();
          tmptype=type.top();type.pop();

          if(type.empty()){
            ng=mid;
            goto flag;
          }

          num.top()--;
          tmptype=type.top();
          if(num.top()==0){
            num.pop();
            type.pop();
          }
            
          if(type.size() && tmptype+1==type.top()){
            num.top()++;
          }else{
            type.push(tmptype+1);             
            num.push(1);
          }

          num.push(tmpnum);
          type.push(0);
          
        }else{
          num.top()--;
          tmptype=type.top();          
          if(num.top()==0){
            num.pop();
            type.pop();
          }
          
          if(type.size() && type.top()==tmptype+1)num.top()++;
          else {
            num.push(1);
            type.push(tmptype+1);
          }
        }
      }
    }
    ok=mid;
    flag:;

  }
  cout<<ok+1<<ENDL;
}
//! ( . _ . ) ! 
//CHECK overflow,vector_size,what to output?