#include<iostream>
#include<algorithm>
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define NMAX 100000
#define INF 1e+6
#define scan(arg) cin>>arg
#define prin(arg) cout<<arg<<"\n"
#define prin2(arg1,arg2) cout<<arg1<<" "<<arg2<<"\n"
using namespace std;
typedef long long ll;
const ll MOD=1000000007;
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

ll Invmod(ll a,ll p){//mod pでのaの逆元を求める
  ll x,y;
  Extgcd(a,p,x,y);
  return (x%p+p)%p;
}
ll n;
ll a[100010];
int main(){
  scan(n);
  rep(i,n)scan(a[i]);
  ll invsum[100010];
  invsum[0]=0;
  rep1(i,n){
    invsum[i]=(invsum[i-1]+Invmod(i,MOD))%MOD;
  }
  ll nmod=1;
  rep1(i,n){
    nmod=(nmod*i)%MOD;
  }
  ll ans=0;
  rep(i,n){
    ans=(ans+(((a[i]*nmod)%MOD)*((invsum[n-i]+invsum[i+1]-1)%MOD))%MOD)%MOD;
  }
  prin(ans);
  

  return 0;
}
