#include <iostream>
#include <iomanip>
#include <string>
#include <stack>
#include <vector>
#include <complex>
#include <math.h>
#include <stdio.h>
#include <algorithm>
#include <utility>
#include <functional>
#include <iterator>
#include <map>
#include <set>
#include <queue>
#include <list>
#include <regex>
#include <limits>
#include <time.h>
#include <cstdint>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <limits.h>
using namespace std;
using pii  = pair<int,int>;
using ll=long long;
using ld=long double;
#define pb push_back
#define mp make_pair
#define sc second
#define fr first
#define stpr setprecision
#define cYES cout<<"YES"<<endl
#define cNO cout<<"NO"<<endl
#define cYes cout<<"Yes"<<endl
#define cNo cout<<"No"<<endl
#define rep(i,n) for(ll i=0;i<(n);++i)
#define Rep(i,a,b) for(ll i=(a);i<(b);++i)
#define rrep(i,n) for(ll i=n-1;i>=0;i--)
#define rRep(i,a,b) for(ll i=a;i>=b;i--)
#define crep(i) for(char i='a';i<='z';++i)
#define psortsecond(A,N) sort(A,A+N,[](const pii &a, const pii &b){return a.second<b.second;});
#define ALL(x) (x).begin(),(x).end()
#define debug(v) cout<<#v<<":";for(auto x:v){cout<<x<<' ';}cout<<endl;
#define endl '\n'
int ctoi(const char c){
  if('0' <= c && c <= '9') return (c-'0');
  return -1;
}
ll gcd(ll a,ll b){return (b == 0 ? a : gcd(b, a%b));}
ll lcm(ll a,ll b){return a*b/gcd(a,b);}
constexpr ll MOD=1000000007;
constexpr ll INF=1000000011;
constexpr ll MOD2=998244353;
constexpr ll LINF = 1001002003004005006ll;
constexpr ld EPS=10e-8;
template <class T, class U> inline bool chmax(T& lhs, const U& rhs) { if (lhs < rhs) { lhs = rhs; return 1; } return 0; }
template <class T, class U> inline bool chmin(T& lhs, const U& rhs) { if (lhs > rhs) { lhs = rhs; return 1; } return 0; }
template<typename T> istream& operator>>(istream& is,vector<T>& v){for(auto&& x:v)is >> x;return is;}
template<typename T,typename U> istream& operator>>(istream& is, pair<T,U>& p){ is >> p.first; is >> p.second; return is;}
template<typename T,typename U> ostream& operator>>(ostream& os, const pair<T,U>& p){ os << p.first << ' ' << p.second; return os;}
template<class T> ostream& operator<<(ostream& os, vector<T>& v){
  for(auto i=begin(v); i != end(v); ++i){
    if(i !=begin(v)) os << ' ';
    os << *i;
  }
  return os;
}

ll C[52][52];
string S[100];
int main(){
  ll H,W;
  cin >> H >> W;
  ll SUM=0;
  queue<pair<pair<ll,ll>,ll>> Q;
  rep(i,H){
    cin >> S[i];
    rep(j,W){
      if(S[i][j]=='.'){
        SUM++;
      }
    }
  }
  Q.push(mp(mp(0,0),1));
  C[0][0]=1;
  H--;W--;
  ll ANS=-1;
  ll Z=0;
  while(!Q.empty()){
    auto X = Q.front();
    Q.pop();
    ll L=X.fr.fr,R=X.fr.sc,K=X.sc;
    //cout << L << " " << R << endl;
    if(L==H && W==R){
      ANS=K;
      break;
    }
    if(L!=0){
      if(C[L-1][R]==0 && S[L-1][R]!='#'){
        Q.push(mp(mp(L-1,R),K+1));
        C[L-1][R]=1;
      }
    }
    if(R!=0){
      if(C[L][R-1]==0 && S[L][R-1]!='#'){
        Q.push(mp(mp(L,R-1),K+1));
        C[L][R-1]=1;
      }
    }
    if(L!=H){
      if(C[L+1][R]==0 && S[L+1][R]!='#'){
        Q.push(mp(mp(L+1,R),K+1));
        C[L+1][R]=1;
      }
    }
    if(R!=W){
      if(C[L][R+1]==0 && S[L][R+1]!='#'){
        Q.push(mp(mp(L,R+1),K+1));
        C[L][R+1]=1;
      }
    }
  }
  if(ANS==-1){
    cout << -1 << endl;
  }
  else{
    cout << SUM-ANS << endl;
  }
}