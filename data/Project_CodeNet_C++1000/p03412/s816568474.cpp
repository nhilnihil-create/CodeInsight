#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <queue>
#include <iomanip>
#define MOD 1000000007
typedef long long ll;
using namespace std;

int main(){
  ll n;
  cin>>n;
  ll a[n+1]={};
  ll b[n+1]={};

  for(int i=0;i<n;i++) cin>>a[i];
  for(int i=0;i<n;i++) cin>>b[i];

  ll ans=0;
  for(int i=29;i>0;i--){
    for(int j=0;j<n;j++){
      a[j]%=(1<<i);
      b[j]%=(1<<i);
    }
    sort(b,b+n);

    ll t=(1<<(i-1));
    ll z=0;
    for(int j=0;j<n;j++){
      z+=lower_bound(b,b+n,2*t-a[j])-lower_bound(b,b+n,t-a[j]);
      //cout<<z<<endl;
      z+=lower_bound(b,b+n,4*t-a[j])-lower_bound(b,b+n,3*t-a[j]);
      //cout<<i<<" "<<a[j]<<" "<<z<<endl;
    }
    if(z%2) ans=ans+(1<<(i-1));
  }

  cout<<ans<<endl;

  return 0;
}
