#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

int main() {
  ll n,k;
  cin >> n >> k;
  vector<ll> a(n);
  for(ll i=0;i<n;i++) {
    cin >> a[i];
  }
  vector<ll> sa(n+1);
  for(ll i=0;i<n;i++) {
    sa[i+1]=sa[i]+a[i];
  }
  vector<ll> aa((n+1)*n/2);
  ll temp=0;
  for(ll i=0;i<n;i++) {
    for(ll j=i+1;j<=n;j++) {
      aa[temp]=sa[j]-sa[i];
      if(j==i) {
        aa[temp]=a[i];
      }
      temp++;
    }
  }
  ll m=40;
  ll ans=0;
  temp=1;
  for(ll i=0;i<m-1;i++) {
    temp*=2;
  }
  while(m--) {
    ll count=0;
    for(ll i=0;i<aa.size();i++) {
      if((aa[i]&(ans+temp))==(ans+temp)) {
        count++;
      }
    }
    if(count>=k) {
      ans+=temp;
    }
    temp/=2;
  }
  cout << ans << endl;
}