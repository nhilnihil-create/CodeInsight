#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

int main(){
  ll n;
  cin >> n;
  ll a[n],b[n];
  for(ll i=0;i<n;i++) cin >> a[i] >> b[i];
  ll ans=0;
  for(ll i=0;i<n;i++) ans+=a[i];
  ll x=ans;
  for(ll i=0;i<n;i++){
    if(a[i]>b[i]) x=min(x,b[i]);
  }
  cout << ans-x << endl;
}
      
    