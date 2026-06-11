#include<iostream>
#include<algorithm>
#define rep(i,n) for(ll i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define NMAX 100000
#define INF 1e+6
#define scan(arg) cin>>arg
#define prin(arg) cout<<arg<<"\n"
#define prin2(arg1,arg2) cout<<arg1<<" "<<arg2<<"\n"
using namespace std;
typedef long long ll;
const ll MAX_P=10000000;
const ll MOD=998244353;
ll fact[MAX_P];

void make_fact(){
  fact[0]=fact[1]=1;
  for(ll i=2;i<MAX_P;i++){
    fact[i]=(fact[i-1]*i)%MOD;
  }
}
ll Extgcd(ll a,ll b,ll &x,ll &y){
  ll d=a;
  if(b!=0){
    Extgcd(b,a%b,y,x);
    y-=(a/b)*x;
  }
  else{
    x=1;y=0;
  }
  return d;
}

ll mod_inv(ll a,ll p){//mod pでのaの逆元を求める
  ll x,y;
  Extgcd(a,p,x,y);
  return (x%p+p)%p;
}
//n!=a*p^e (a,p互いに素,p素数) とした時のeとa mod p を求める
ll mod_fact(ll n,ll p,ll& e){
  e=0;
  if(n==0) return 1;
  
  ll res=mod_fact(n/p,p,e);
  e+=n/p;

  if(n/p%2!=0) return res*(p-fact[n%p])%p;
  return res*fact[n%p]%p;
}

//nCk mod pを求める
ll mod_comb(ll n,ll k,ll p){
  if(n<0||k<0||n-k<0) return 0;
  ll e1,e2,e3;
  ll a1=mod_fact(n,p,e1),a2=mod_fact(k,p,e2),a3=mod_fact(n-k,p,e3);
  if(e1>e2+e3) return 0;
  return a1*mod_inv(a2*a3%p,p)%p;
}
ll n,a,b,k;

int main(){
  make_fact();
  scan(n);scan(a);scan(b);scan(k);
  ll res=0;
  rep(x,n+1){
    if((k-a*x)%b==0){
      ll y=(k-a*x)/b;
      res=(res+mod_comb(n,x,MOD)*mod_comb(n,y,MOD)%MOD)%MOD;
    }
  }
  prin(res);  
  return 0;
}
