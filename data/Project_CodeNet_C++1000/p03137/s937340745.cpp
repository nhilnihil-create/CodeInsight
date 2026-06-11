#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (ll i = 0; i < (n); ++i)

int main() {
  ll n,m;
  cin >> n >> m;
  vector<ll> x(m);
  rep(i,m) cin >> x[i];
  
  if(n>=m){
    cout << 0 << endl;
    return(0);
  }
  
  sort(x.begin(),x.end());
  
  ll ans=x[m-1]-x[0];
  
  vector<ll> y(m-1);
  rep(i,m) y[i] = x[i+1]-x[i];
  sort(y.begin(),y.end());
  reverse(y.begin(),y.end());
  
  rep(i,n-1){
    ans -= y[i];
  }
  
  cout << ans << endl;
  
  return(0);
}