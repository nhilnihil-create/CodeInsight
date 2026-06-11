#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>
#define MOD 1000000007
typedef long long ll;
using namespace std;

#define N 100010

ll inv[N],fac[N],ifac[N];

int main(){
  int n;
  cin>>n;
  ll a[n+1]={};
  ll s[n+1]={};
  for(int i=1;i<=n;i++){
    cin>>a[i];
  }

  inv[0]=1;inv[1]=1;fac[1]=1;ifac[1]=1;fac[0]=1;ifac[0]=1;
  for(int i=2;i<=n+1;i++){
    inv[i]=(-MOD/i)*inv[MOD%i]%MOD;
    fac[i]=fac[i-1]*i%MOD;
    ifac[i]=ifac[i-1]*inv[i]%MOD;
    //cout<<inv[i]<<" "<<fac[i]<<" "<<ifac[i]<<endl;
  }

  ll ans=0;
  for(int i=1;i<=n;i++){
    s[i]=(s[i-1]+inv[i])%MOD;
  }

  for(int i=1;i<=n;i++){
    ans=ans+a[i]*(s[i]+s[n-i+1]-s[1])%MOD;
    ans=(ans+MOD)%MOD;
  }
  ans=ans*fac[n]%MOD;

  cout<<(ans+MOD)%MOD<<endl;
  return 0;
}
