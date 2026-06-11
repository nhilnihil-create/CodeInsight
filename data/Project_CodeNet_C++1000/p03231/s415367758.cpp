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

// oooooooooo
// xoxoxoxoxo


int main(){
  ll N,M; cin>>N>>M;
  string s,t; cin>>s>>t;
  ll L = lcm(N,M);
  bool ok = true;
  if(gcd(N,M)>1){
    ll nol = L/N;
    ll mol = L/M;
    for(ll i=0;i<L;++i){
      if(i%nol==0 && i%mol==0){
        ll idx_s = i/nol;
        ll idx_t = i/mol;
        if(s[idx_s]!=t[idx_t]){ ok = false; break;}
      }
    }
  }else{
    if(s[0]!=t[0]){ok=false;}
  }
  if(ok){ cout << L <<"\n";}
  else{ cout << "-1\n"; }
}