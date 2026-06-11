#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>
#define MOD 1000000007
#define INF (1e18)
typedef long long ll;
using namespace std;

int main(){
  ll n;
  ll X;
  cin>>n>>X;

  ll x[n+1]={};
  ll s[n+1]={};
  for(int i=1;i<=n;i++){
    cin>>x[i];
    s[i]=s[i-1]+x[i];
  }

  ll sum=0;
  for(int i=1;i<=n;i++){
    sum+=x[i]*5+X;
  }
  ll ans=sum;
  for(int i=1;i<=n;i++){
    ll tmp=0;
    tmp+=5*(s[n]-s[n-i]);
    ll u=5;
    for(int j=n-i;j>0;j-=i){
      if(j-i<0) tmp+=u*(s[j]);
      else tmp+=u*(s[j]-s[j-i]);
      u+=2;
    }
    tmp+=i*X;
    if(tmp<0) continue;
    //cout<<tmp<<endl;
    ans=min(ans,tmp);
  }

  cout<<ans+n*X<<endl;



  return 0;
}
