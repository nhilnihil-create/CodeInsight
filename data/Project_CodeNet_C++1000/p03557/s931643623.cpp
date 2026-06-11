#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <iomanip>
#include <utility>
#include <tuple>
#include <functional>
#include <bitset>
#include <cassert>
#include <complex>
#include <time.h>
#define ll long long
#define double long double
#define itn int
#define endl '\n'
#define co(ans) cout<<ans<<endl;
#define COYE cout<<"YES"<<endl;
#define COYe cout<<"Yes"<<endl;
#define COye cout<<"yes"<<endl;
#define CONO cout<<"NO"<<endl;
#define CONo cout<<"No"<<endl;
#define COno cout<<"no"<<endl;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FFOR(i,a,b) for(int i=(a);i<=(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define RREP(i,n)  FFOR(i,1,n)
#define ALL(V) (V).begin(),(V).end()
#define SORT(V) sort((V).begin(),(V).end())
#define REVERSE(V) reverse((V).begin(),(V).end())
#define INF ((1LL<<62)-(1LL<<31))
#define EPS 1e-10
#define PI 3.141592653589793238
#define MOD 1000000007
#define MAX 5100000
template<class T>bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}return 0;}
template<class T>bool chmin(T &a,const T &b){if(b<a){a=b;return 1;}return 0;}
const int vx[4]={0,1,0,-1},vy[4]={1,0,-1,0};
using namespace std;

int main(){
  ll N,ans=0;
  cin>>N;
  
  vector<ll> A,B,C;
  REP(i,N){
    ll a;
    cin>>a;
    A.push_back(a);
  }
  REP(i,N){
    ll a;
    cin>>a;
    B.push_back(a);
  }
  REP(i,N){
    ll a;
    cin>>a;
    C.push_back(a);
  }
  
  SORT(A);
  SORT(B);
  SORT(C);
  
  REP(i,N){
    auto Iter1=lower_bound(ALL(A),B[i]);
    ll Adx=distance(A.begin(),Iter1);
    auto Iter2=upper_bound(ALL(C),B[i]);
    ll Cdx=distance(Iter2,C.end());
    ans+=Adx*Cdx;
  }
  
  cout<<ans<<endl;
  return 0;
}