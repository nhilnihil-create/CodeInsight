#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

int main() {
  ll n;
  cin >> n;
  vector<ll> a(n);
  for(ll i=0;i<n;i++) {
    cin >> a[i];
  }
  ll temp=0;
  ll ans=0;
  for(ll i=n-1;i>-1;i--) {
    if(a[i]>i || a[i]<temp) {
      cout << -1 << endl;
      return 0;
    }
    if(a[i]!=temp) {
      ans+=a[i];
      temp=a[i];
    }
    if(temp>0) {
      temp--;
    }
  }
  cout << ans << endl;
}