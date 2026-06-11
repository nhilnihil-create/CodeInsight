#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define REPR(i,n) for(int i=n; i>-1; --i)
#define ALL(a) (a).begin(),(a).end()
#define FILL(a,n,x); REP(i,(n)){ (a)[i]=(x); }
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
int __stoi(string s){ return atoi(s.c_str()); }
ll sum(ll a[],ll N){ return accumulate(a,a+N,0LL);}
ll gcd(ll a,ll b){if(a<b)swap(a,b); return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){if(a<b){swap(a,b);} return a/gcd(a,b)*b;}
template<class T> void chmax(T& a, T b){ if(a<b){a=b;} }
template<class T> void chmin(T& a, T b){ if(a>b){a=b;} }

int main(){
  ll inf = pow(10,12);
  ll A,B,Q; cin>>A>>B>>Q;
  ll s[A+2];
  s[0] = -inf;
  for(int i=1;i<=A;++i){ cin>>s[i]; }
  s[A+1] = inf;
  ll t[B+2];
  t[0] = -inf; 
  for(int i=1;i<=B;++i){ cin>>t[i];}
  t[B+1] = inf;
  
  REP(count,Q){
    ll x; cin>>x;
    ll* iters = lower_bound(s,s+A+2,x);
    ll* itert = lower_bound(t,t+B+2,x);
    ll hs = *(iters-1);
    ll ms = *iters;
    ll ht = *(itert-1);
    ll mt = *itert;
    
    ll c1 = min( abs(x-hs) + abs(hs-ht), abs(x-ht)+abs(ht-hs) );
	ll c2 = min( abs(x-hs) + abs(hs-mt), abs(x-mt)+abs(mt-hs) );
    ll c3 = min( abs(x-ms) + abs(ms-ht), abs(x-ht)+abs(ht-ms) );
    ll c4 = min( abs(x-ms) + abs(ms-mt), abs(x-mt)+abs(mt-ms) );
   
    ll ans = min({c1,c2,c3,c4});
    cout << ans <<"\n";
  }
  
}