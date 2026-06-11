#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
ll mod=1e9+7;

int main() {
  ll n;
  ll zero=0;
  cin >> n;
  map<ll,ll> count;
  for(ll i=2;i<=n;i++) {
    ll temp=i;
    for(ll j=2;j*j<=temp;j++) {
      while(temp%j==0) {
        temp/=j;
        count[j]++;
      }
    }
    if(temp!=1) {
      count[temp]++;
    }
  }
  ll n2=0,n4=0,n24=0,n14=0,n74=0;
  for(auto p:count) {
    if(p.second>1) {
      n2++;
    }
    if(p.second>3) {
      n4++;
    }
    if(p.second>13) {
      n14++;
    }
    if(p.second>23) {
      n24++;
    }
    if(p.second>73) {
      n74++;
    }
  }
  ll ans=0;
  ans+=max(n4*(n4-1)*(n2-2)/2,zero);
  ans+=max(n24*(n2-1),zero);
  ans+=max(n14*(n4-1),zero);
  ans+=n74;
  cout << ans << endl;
}