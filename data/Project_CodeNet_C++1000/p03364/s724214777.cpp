#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

int main() {
  ll n;
  cin >> n;
  vector<string> s(n);
  for(ll i=0;i<n;i++) {
    cin >> s[i];
  }
  vector<string> s2(n);
  for(ll i=0;i<n;i++) {
    string temp;
    for(ll j=0;j<n;j++) {
      temp=temp+s[j][i];
    }
    s2[i]=temp;
  }
  ll ans=0;
  for(ll i=0;i<n;i++) {
    bool flag=true;
    for(ll k=0;k<n;k++) {
      string temp=s[(k+i)%n];
      string temp2=s2[k].substr(i)+s2[k].substr(0,i);
      if(temp!=temp2) {
        flag=false;
        break;
      }
    }
    if(flag) {
      ans+=n;
    }
  }
  cout << ans << endl;
}