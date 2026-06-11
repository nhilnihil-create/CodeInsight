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
  int N,C; cin>>N>>C;
  int d[C+1][C+1],num[3][C+1];
  
  FILL2(d,C+1,C+1,0);
  FILL2(num,3,C+1,0);
  
  for(int ca=1;ca<=C;++ca){
    for(int cb=1;cb<=C;++cb){
      cin >> d[ca][cb]; // 色caを色cbに変更するコスト
    }
  }
  for(int i=1;i<=N;++i){
    for(int j=1;j<=N;++j){
      int c; cin >> c;
      ++num[ (i+j)%3 ][c];  //位置 (i+j)%3 における色cの総数
    }
  }
  
  ll ans = pow(10,10);
  for(int c1=1;c1<=C;++c1){
    for(int c2=1;c2<=C;++c2){
      if(c1==c2){continue;}
      for(int c3=1; c3<=C;++c3){
        if(c1==c3 || c2==c3){continue;}
        ll temp = 0;
        for(int pc=1;pc<=C;++pc){ temp += d[pc][c1]*num[0][pc]; }
        for(int pc=1;pc<=C;++pc){ temp += d[pc][c2]*num[1][pc]; }
        for(int pc=1;pc<=C;++pc){ temp += d[pc][c3]*num[2][pc]; }
        if(temp<ans){ ans = temp; }
      }
    }
  }
  cout << ans <<"\n";
}
