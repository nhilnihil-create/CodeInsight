#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;


int main() {
  ll n;
  cin >> n;

  ll ans=0;
  for(ll i=1;i*i<=n;i++) {
    if(n%i==0) {
      if(n/i!=1&&n/i!=2&&n/i-1>i) {
        ans+=(n/i-1);
      }
    }
  }
  cout << ans << endl;
}