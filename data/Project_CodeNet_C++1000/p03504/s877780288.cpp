#include <iostream>
#include <cstdio>
#include <cassert>
#include <algorithm>
#include <vector>
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
  int s[1000000],t[1000000],c[1000000];
  int cumu[2000002],r[2000002]={0};
  REP(i,N){
    cin >> s[i] >> t[i] >> c[i];
  }
  // 各チャンネルに関する処理(imos法)
  for(int ch=1;ch<=C;++ch){
    FILL(cumu,2000002,0);
    REP(i,N){
      if(c[i]==ch){
        ++cumu[s[i]*2-1]; // 縁作り
        --cumu[t[i]*2];
      }
    }
    for(int i=1;i<2000002;++i){
      cumu[i] += cumu[i-1]; //値埋め
    }
    REP(i,2000002){
      if(cumu[i]>0){ ++r[i]; } //利用時間帯に1加算
    }
  }
  cout << (int)*max_element(r,r+2000002) <<endl;
}