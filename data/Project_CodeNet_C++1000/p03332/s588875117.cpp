#include<bits/stdc++.h>
using namespace std;
#define rep(i,j,n) for(int i=(int)(j);i<(int)(n);i++)
#define REP(i,j,n) for(int i=(int)(j);i<=(int)(n);i++)
#define MOD 998244353
#define int long long
#define ALL(a) (a).begin(),(a).end()
#define vi vector<int>
#define vii vector<vi>
#define pii pair<int,int>
#define priq priority_queue<int>
#define disup(A,key) distance(A.begin(),upper_bound(ALL(A),(int)(key)))
#define dislow(A,key) distance(A.begin(),lower_bound(ALL(A),(int)(key)))
#define tii tuple<int,int,int>
#define Priq priority_queue<int,vi,greater<int>>
#define pb push_back
#define mp make_pair
#define INF (1ll<<60)
int modpow(int X,int Y){
  int sum=X,cnt=1;
  vi A;
  while(Y>=cnt){
    cnt*=2;
    A.pb(sum);
    sum*=sum;
    sum%=MOD;
  }
  int ret=1;
  int M=A.size();
  REP(i,1,M){
    if(Y>=(1ll<<M-i)){
      Y-=(1ll<<M-i);
      ret*=A[M-i];
      ret%=MOD;
    }
  }
  return ret;
}
int finv[500000],fac[500000];
void COMinit(){
  finv[0]=fac[0]=finv[1]=fac[1]=1;
  rep(i,2,500000){
    fac[i]=fac[i-1]*i%MOD;
    finv[i]=finv[i-1]*modpow(i,MOD-2)%MOD;
  }
}
int COM(int X,int Y){
  if(X<Y) return 0;
  if(X<0||Y<0) return 0;
  return fac[X]*finv[Y]%MOD*finv[X-Y]%MOD;
}
signed main(){
  COMinit();
  int N,A,B,K; cin>>N>>A>>B>>K;
  int ans=0;
  REP(i,0,N){
    int X=K-i*A;
    if(X%B==0){
      ans+=COM(N,i)*COM(N,X/B)%MOD;
      ans%=MOD;
    }
  }
  cout<<ans<<endl;
  }

