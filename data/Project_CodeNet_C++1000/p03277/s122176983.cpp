#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <time.h>
#include <tuple>
#include <utility>
#include <vector>
#define ll long long
#define itn int
#define endl '\n'
#define co(ans) cout<<ans<<endl
#define COYE cout<<"YES"<<endl
#define COYe cout<<"Yes"<<endl
#define COye cout<<"yes"<<endl
#define CONO cout<<"NO"<<endl
#define CONo cout<<"No"<<endl
#define COno cout<<"no"<<endl
#define FORE(i,a) for(auto &i:a)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FFOR(i,a,b) for(int i=(a);i<=(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define RREP(i,n)  FFOR(i,1,n)
#define PB push_back
#define MP make_pair
#define ALL(V) (V).begin(),(V).end()
#define SORT(V) sort((V).begin(),(V).end())
#define REVERSE(V) reverse((V).begin(),(V).end())
#define EACH(V,i) for(typeof((V).begin()) i=(V).begin();i!=(V).end();++i)
#define equals(a,b) (fabs((a)-(b))<EPS)
#define INF ((1LL<<62)-(1LL<<31))
#define EPS 1e-10
#define PI 3.141592653589793238
#define MOD 1000000007
#define MMOD 998244353
#define MAX 2010101
using namespace std;
using Edge=pair<ll,ll>;
using Graph=vector<vector<int>>;
inline int toInt(string s){int v;istringstream sin(s);sin>>v;return v;}
template<class T>inline string toString(T x){ostringstream sout;sout<<x;return sout.str();}
template<class T>bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}return 0;}
template<class T>bool chmin(T &a,const T &b){if(b<a){a=b;return 1;}return 0;}
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef long long LL;
const int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

ll N;

class BIT{
public:
  ll n;
  vector<ll> bit;
  BIT(ll n):n(n),bit(n+1,0){}
  
  void add(ll i,ll x){
    if(i==0) return;
    for(ll k=i;k<=n;k+=(k & -k)) bit[k]+=x;
  }
  
  ll sum(ll i){
    ll s=0;
    if(i==0) return s;
    for(ll k=i;k>0;k-=(k & -k)) s+=bit[k];
    return s;
  }
};

// 数列Sの転倒数(i<j かつ S[i]>S[j] を満たすものの数)
ll inversion(vector<ll> S){
  ll mn=0;
  RREP(i,N) chmin(mn,S[i]);
  REP(i,N+1) S[i]-=mn,S[i]++;
  
  ll num=0;
  BIT U(N+1);
  REP(i,N+1){
    num+=i-U.sum(S[i]);
    U.add(S[i],1);
  }
  return num;
}

// 中央値がmid以上になる部分列の数
ll cnt(vector<ll> A,ll mid){
  vector<ll> B(N),S(N+1);
  REP(i,N){
    if(A[i]>=mid) B[i]=1;
    else B[i]=-1;
  }
  
  S[0]=0;
  RREP(i,N) S[i]=S[i-1]+B[i-1];
  
  return N*(N+1)/2-inversion(S);
}

int main(){
  cin>>N;
  vector<ll> A(N);
  REP(i,N) cin>>A[i];
  
  ll ok=0ll,ng=MOD;
  while(abs(ok-ng)>1){
    ll mid=(ok+ng)/2;
    if(2*cnt(A,mid)>=N*(N+1)/2) ok=mid;
    else ng=mid;
  }
  cout<<ok<<endl;
  return 0;
}