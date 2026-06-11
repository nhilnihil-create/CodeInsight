#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

int main() {
  ll n;
  cin >> n;
  ll count=0;
  for(ll i=1;i<=n;i++) {
    for(ll j=i+1;j<=n;j++) {
      if(n%2) {
        if(i+j!=n) {
          count++;
        }
      }
      else {
        if(i+j!=n+1) {
          count++;
        }
      }
    }
  }
  cout << count << endl;
  for(ll i=1;i<=n;i++) {
    for(ll j=i+1;j<=n;j++) {
      if(n%2) {
        if(i+j!=n) {
          cout << i << " " << j << endl;
        }
      }
      else {
        if(i+j!=n+1) {
          cout << i << " " << j << endl;
        }
      }
    }
  }
}