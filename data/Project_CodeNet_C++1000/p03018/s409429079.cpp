#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

int main() {
  string s;
  cin >> s;
  ll ans=0;
  ll a=0;
  bool b=false;
  for(ll i=0;i<s.size();i++) {
    if(s[i]=='A') {
      if(b) {
        a=0;
      }
      a++;
      b=false;
    }
    else if(s[i]=='B') {
      if(b) {
        a=0;
      }
      b=true;
    }
    else {
      if(b) {
        ans+=a;
      }
      else {
        a=0;
      }
      b=false;
    }
  }
  cout << ans << endl;
}