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

ll N,A[200007];

bool isprime(ll N){
  if(N==1){
    return 0;
  }
  if(N==2){
    return 1;
  }
  Rep(i,2,sqrt(N)+1){
    if(N%i==0){
      return 0;
    }
  }
  return 1;
}

vector<ll> Prime_Array(ll Left, ll Right){ //Left以上Right以下の素数の配列
  vector<ll> RE_Prime_Array;
  Rep(i,Left,Right+1){
    if(isprime(i)){
      RE_Prime_Array.pb(i);
    }
  }
  return RE_Prime_Array;
}

vector<ll> N1,N2,N3,N4;

int main(){
  cin >> N;
  ll k=0;
  vector<ll> V=Prime_Array(12,55555);
  rep(i,V.size()){
    if(V[i]%5==1){
      k++;
      cout << V[i];
      if(k!=N){
        cout << " ";
      }
    }
    if(k==N){
      break;
    }
  }
  cout << endl;
}
