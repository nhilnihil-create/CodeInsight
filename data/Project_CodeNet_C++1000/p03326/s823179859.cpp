#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define REPR(i,n) for(int i=n; i>-1; --i)
#define ALL(a) (a).begin(),(a).end()
#define FILL(a,x); REP(i,sizeof(a)){ (a)[i]=(x); }
#define CINA(a,n); REP(i,(n)){ cin >> (a)[i]; }
#define FILL2(a,n,m,x); REP(i,(n)){ REP(j,(m)){(a)[i][j]=(x);} }
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

ll x[1010],y[1010],z[1010];
ll v[1010];

int main(){
  int N,M; cin>>N>>M;
  REP(i,N){
    cin>>x[i]>>y[i]>>z[i];
  }
  
  ll ans = -1;
  for(int bits=0;bits<pow(2,3);++bits){  
    int temp = bits;
    int fugou;
    
    if(temp%2==1){ fugou = 1;}
    else{ fugou = -1;}
    REP(i,N){ v[i] = x[i]*fugou; }
    temp /= 2;
    
    if(temp%2==1){ fugou = 1; }
    else{ fugou = -1;}
    REP(i,N) { v[i] += y[i]*fugou; }
    temp /= 2;
    
    if(temp%2==1){ fugou = 1; }
    else{ fugou = -1;}
    REP(i,N){ v[i] += z[i]*fugou; }
    
    sort(v,v+N,greater<ll>());
    ll cand = sum(v,M);
    if(cand>ans){ ans = cand;}
  }
  cout << ans <<"\n";
}