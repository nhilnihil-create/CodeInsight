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

vector<vector<ll>> E(10007);  //各点の持つ子の情報
ll color[10007];              //訪れ所の
bool B[10007];               //outに入ってるか否か
ll N,M,a,b;                   //N:頂点数　M:エッジ数
ll indeg[10007],D[10007];             //各点の入次数。訪問した回数だけ減っていく。
ll C[10007];
ll ANS[10007],ans;
ll K=0;
queue<ll> Q;

void bfs(ll s){
  while(!Q.empty()){
    ll u=Q.front();
    B[u]=true;
    ANS[u]=C[K];
    ans+=C[K];
    K++;
    Q.pop();
    rep(i,E[u].size()){
      ll v=E[u][i];
      indeg[v]--;
      if(indeg[v]==1 && !B[v]){
        B[v]=true;
        Q.push(v);
      }
    }
  }
}

void topological_sort(){
  Rep(i,1,N+1){
    B[i]=false;
  }
  Rep(i,1,N+1){                 // 0indexed か 1indexed か で変える
    if(indeg[i]==1 && !B[i]){
      Q.push(i);
    }
  }
}

int main(){
  cin >> N;
  rep(i,N-1){
    ll  A,B;
    cin >> A >> B;
    E[A].pb(B);
    E[B].pb(A);
    indeg[A]++;
    indeg[B]++;
    D[A]++;
    D[B]++;
  }
  rep(i,N){
    cin >> C[i];
  }
  sort(C,C+N);
  topological_sort();
  bfs(1);
  cout << ans - C[N-1] << endl;
  Rep(i,1,N+1){
    cout << ANS[i];
    if(i!=N){
      cout  << " ";
    }
  }
  cout << endl;
}