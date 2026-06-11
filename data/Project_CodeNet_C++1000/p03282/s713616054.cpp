#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int,int>P;

int main() {
  string s;
  cin >> s;
  ll k;
  cin >> k;
  ll n = min(k, (ll)s.size());
  int ans = 1;
  if(s[0]!='1') ans = s[0]-'0';
  else {
    for (int i = 1; i < (n); ++i){
      if(s[i]!='1') {
        ans = s[i]-'0';
        break;
      }
      else continue;
    }
  }
  cout << ans << endl;
}