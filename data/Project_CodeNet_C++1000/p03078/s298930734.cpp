#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define REPR(i,n) for(int i=n; i>-1; --i)
#define ALL(a) (a).begin(),(a).end()
#define INIT(a,n,x); REP(i,(n)){ (a)[i]=(x); }
#define CINA(a,n); REP(i,(n)){ cin >> (a)[i]; }
#define INIT2(a,n,m,x); REP(i,(n)){ REP(j,(m)){(a)[i][j]=(x);} }
#define CINA2(a,n,m); REP(i,(n)){ REP(j,(m)){cin >> (a)[i][j];} }
#define Liny "Yes\n"
#define Linn "No\n"
#define LINY "YES\n"
#define LINN "NO\n"

#define umap unordered_map
//cout << setfill('0') << right << setw(4) << 12; // "0012"
int keta(ll x){ if(x<10){return 1;} else{return keta(x/10) + 1;}}
int keta_wa(ll x){ if(x<10){return x;} else{return keta_wa(x/10) + x%10;} }
int ctoi(char c){ return ( (c>='0' && c<='9')? c - '0': 0 );}
ll sum(ll a[],ll N){ return accumulate(a,a+N,0LL);}
ll gcd(ll a,ll b){if(a<b)swap(a,b); return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){if(a<b){swap(a,b);} return a/gcd(a,b)*b;}

ll solve(){
  ll X,Y,Z,K; cin >>X>>Y>>Z>>K;
  ll a[X]; CINA(a,X); sort(a,a+X,greater<ll>());
  ll b[Y]; CINA(b,Y); sort(b,b+Y,greater<ll>());
  ll c[Z]; CINA(c,Z); sort(c,c+Z,greater<ll>());
  vector<ll> v;
  REP(i,X){
    REP(j,Y){
      REP(k,Z){
        if( (i+1)*(j+1)*(k+1)<= K ){ v.push_back( a[i]+b[j]+c[k] ); } 
        else{ break;}
      }
    }
  }
  sort(ALL(v),greater<ll>());
  for(int i=0;i<K;++i){
    cout << v.at(i) <<"\n";
  }
  
}

int main(){
  solve();
}


