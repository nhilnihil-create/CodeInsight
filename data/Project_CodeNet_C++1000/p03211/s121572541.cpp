#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (ll i=0; i<(n); ++i)
typedef long long ll;
bool debug=false;
int main(){
  string s; cin >> s;
  ll ans = 753;
  rep(i,s.size()-2){
    ll p = 100*(s[i]-'0') +10*(s[i+1]-'0') +(s[i+2]-'0');
    ans = min(ans, abs(753-p));
  }
  cout << ans;
  return 0;
}
