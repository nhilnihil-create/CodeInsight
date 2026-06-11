#include <iostream>
#include <cstdio>
#include <cassert>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <numeric>
#include <cmath>
using namespace std;
typedef long long ll;
typedef long double ld;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define REPR(i,n) for(int i=n; i>-1; --i)
#define ALL(a) (a).begin(),(a).end()
#define FILL(a,n,x); REP(i,n){ (a)[i]=(x); }
#define CINA(a,n); REP(i,(n)){ cin >> (a)[i]; }
#define FILL2(a,n,m,x); REP(i,(n)){ REP(j,(m)){(a)[i][j]=(x);} }
#define CINA2(a,n,m); REP(i,(n)){ REP(j,(m)){cin >> (a)[i][j];} }
#define Liny "Yes\n"
#define Linn "No\n"
#define LINY "YES\n"
#define LINN "NO\n"
#define pii pair<int,int>
#define PI 3.141592653589793

//cout << setfill('0') << right << setw(4) << 12; // "0012"
int keta(ll x){ if(x<10){return 1;} else{return keta(x/10) + 1;}}
int keta_wa(ll x){ if(x<10){return x;} else{return keta_wa(x/10) + x%10;} }
int ctoi(char c){ return ( (c>='0' && c<='9')? c - '0': 0 );}
ll sum(ll a[],ll N){ return accumulate(a,a+N,0LL);}
ll gcd(ll a,ll b){if(a<b)swap(a,b); return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){if(a<b){swap(a,b);} return a/gcd(a,b)*b;}

int main(){
  int H,W,D; cin>>H>>W>>D;
  pii p[H*W+1];
  REP(i,H){
    REP(j,W){
      int a; cin>>a;
      p[a] = make_pair(i,j);
    }
  }
  
  int d[H*W+1] = {0};
  for(int i=D+1; i<=H*W; ++i){
    d[i] = d[i-D] + abs(p[i].first-p[i-D].first) + abs( p[i].second-p[i-D].second );
  }
  
  int Q; cin>>Q;
  REP(count,Q){
    int L,R; cin>>L>>R;
    ll ans = d[R]-d[L];
    cout << ans << "\n";
  }
}
