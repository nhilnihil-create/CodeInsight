#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ll n;
  cin >> n;
  vector<ll> a(n);
  for(ll i=0;i<n;i++){
    cin >> a[i];
  }
  vector<ll> b(n);
  for(ll i=0;i<n;i++){
    b[i] = a[i] - i+1;
  }
  
  sort(b.begin(),b.end());
  ll x;
  if(n%2 == 1){
    x = b[n/2];
  }else{
    x = (b[n/2-1]+b[n/2])/2;
  }
  
  ll ans = 0;
  for(ll i=0;i<n;i++){
    ans += abs(b[i]-x);
  }
  
  cout << ans << endl;
  
  return(0);
}