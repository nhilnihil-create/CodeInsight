#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

int main() {
  ll n;
  cin >> n;
  string s;
  cin >> s;
  vector<ll> count(n+1);
  for(ll i=0;i<n;i++) {
    if(s[i]=='#') {
      count[i+1]=count[i]+1;
    }
    else {
      count[i+1]=count[i];
    }
  }
  ll ans=n;
  for(ll i=0;i<n+1;i++) {
    ans=min(ans,count[i]+(n-i-(count[n]-count[i])));
  }
  cout << ans << endl;
}