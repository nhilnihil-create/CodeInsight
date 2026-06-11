#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (ll i = 0; i < (n); ++i)

int main() {
  ll n;
  cin >> n;
  vector<ll> a(n),b(n);
  vector<ll> dif(n);
  ll asum=0,bsum=0;
  rep(i,n){
    cin >> a[i];
    asum += a[i];
  }
  rep(i,n){
    cin >> b[i];
    bsum += b[i];
  }
  
  if(asum < bsum){
    cout << "-1" << endl;
    return(0);
  }
  
  ll ans=0;
  ll need=0;
  vector<ll> c(n);
  rep(i,n){
    c[i] = a[i] - b[i];
    if(c[i] < 0){
      ans++;
      need += c[i];
    }
  }
  
  sort(c.begin(),c.end());
  reverse(c.begin(),c.end());
  
  ll i=0;
  while(need < 0){
    need += c[i];
    ans++;
    i++;
  }
  
  cout << ans << endl;
  
  return(0);
}