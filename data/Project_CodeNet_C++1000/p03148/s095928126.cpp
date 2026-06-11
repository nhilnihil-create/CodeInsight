#include <iostream>
#include <iomanip>
#include <string>
#include <stack>
#include <vector>
#include <math.h>
#include <stdio.h>
#include <algorithm>
#include <utility>
#include <functional>
#include <map>
#include <set>
#include <queue>
#include <list>
using namespace std;
using pii  = pair<int,int>;
using ll=long long;
using ld=long double;
#define pb push_back
#define mp make_pair
#define stpr setprecision
#define cYES cout<<"YES"<<endl
#define cNO cout<<"NO"<<endl
#define cYes cout<<"Yes"<<endl
#define cNo cout<<"No"<<endl
#define rep(i,n) for(ll i=0;i<(n);++i)
#define Rep(i,a,b) for(ll i=(a);i<(b);++i)
#define rrep(i,n) for(int i=n-1;i>=0;i--)
#define rRep(i,a,b) for(int i=a;i>=b;i--)
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
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
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

int ncnt[100007];

int main() {
  ll K,N,x=0;
  ll sum=0;
  priority_queue<ll> PQ;
  pair<ll,ll> dt[100007];   // first taste , second diffference
  cin >> N >> K;
  rep(i,N){
    cin >> dt[i].second >> dt[i].first;
  }
  sort(dt,dt+N);
  reverse(dt,dt+N);
  rep(i,K){    //うまい順に取っていく
    if(ncnt[dt[i].second]>0){
      PQ.push(-dt[i].first);
    }
    else{
      x++;
    }
    ncnt[dt[i].second]++;
    sum+=dt[i].first;
  }
  ll ma=sum+x*x;
  ll now=K;
  while(now<N){   //N個すべて検討するまで種類を増やしていく
    if(PQ.empty()){
      break;
    }
    sum -= -PQ.top();
    PQ.pop();
    Rep(i,now,N){
      if(ncnt[dt[i].second]==0){
        ncnt[dt[i].second]++;
        sum+=dt[i].first;
        x++;
        ma=max(ma,sum+x*x);
        now=i+1;
        break;
      }
    }
  }
  cout << ma << endl;
}