#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (ll i = 0; i < (n); ++i)

int main() {
  ll n,k;
  cin >> n >> k;
  double ans=0;
  rep(i,n){
    ll s=i+1;
    double p=1.0/n;
    while(s<k){
      s *= 2;
      p *= 0.5;
    }
    ans += p;
  }
  
  cout << setprecision(12) << ans << endl;
}