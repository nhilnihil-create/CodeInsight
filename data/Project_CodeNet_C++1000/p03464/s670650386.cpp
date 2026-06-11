#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

int main() {
  ll k;
  cin >> k;
  vector<ll> a(k);
  for(ll i=0;i<k;i++) {
    cin >> a[i];
  }
  reverse(a.begin(),a.end());
  ll mi=2;
  ll mx=2;
  for(ll i=0;i<k;i++) {
    mi=(mi+a[i]-1)/a[i]*a[i];
    mx=mx/a[i]*a[i]+a[i]-1;
    if(mi>mx) {
      cout << -1 << endl;
      return 0;
    }
  }
  cout << mi << " " << mx << endl;
}