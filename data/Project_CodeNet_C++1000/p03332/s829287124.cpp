#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
struct __INIT{__INIT(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(15);}} __init;
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
//constexpr int MOD=1000000007;
constexpr int MOD=998244353;
#define INF (1<<30)
#define LINF (lint)(1LL<<56)
#define endl "\n"
#define rep(i,n) for(lint (i)=0;(i)<(n);(i)++)
#define reprev(i,n) for(lint (i)=(n-1);(i)>=0;(i)--)
#define Flag(x) (1<<(x))
#define Flagcount(x) __builtin_popcount(x)
#define pint pair<int,int>
#define pdouble pair<double,double>
#define plint pair<lint,lint>
#define fi first
#define se second
typedef long long lint;
int dx[8]={1,1,0,-1,-1,-1,0,1};
int dy[8]={0,1,1,1,0,-1,-1,-1};
const int MAX_N=2e5+5;

lint fac[510000],finv[510000],inv[510000];
void COMinit(){
  fac[0]=fac[1]=1;
  finv[0]=finv[1]=1;
  inv[1]=1;
  for(int i=2;i<510000;i++){
    fac[i]=fac[i-1]*i%MOD;
    inv[i]=MOD-inv[MOD%i]*(MOD/i)%MOD;
    finv[i]=finv[i-1]*inv[i]%MOD;
  }
}
lint COM(lint n,lint k){
  if (n<k) return 0;
  if (n<0 || k<0) return 0;
  return fac[n]*(finv[k]*finv[n-k]%MOD)%MOD;
}
lint facdiv(lint n,lint k){
  if (n<k) return 0;
  if (n<0 || k<0) return 0;
  return (fac[n]*finv[k])%MOD;
}

int main(void){
    COMinit();
    lint N,A,B,K;
    lint ans=0;
    cin >> N >> A >> B >> K;
    for(int i=0;i<=N;i++){
        if((K-A*i)%B!=0) continue;
        lint a=i,b=(K-A*i)/B;
        lint add=(COM(N,a)*COM(N,b))%MOD;
        ans=(ans+add)%MOD;
    }
    cout << ans << endl;
}
