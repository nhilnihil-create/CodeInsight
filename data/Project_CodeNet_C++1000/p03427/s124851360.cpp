#include <bits/stdc++.h>
#define rep(i,cc,n) for(int i=cc;i<=n;++i)
using namespace std;
using ll = long long;

ll f(string s) {
  ll n = 0;
  rep(i,0,s.size()-1) {
    n += (s[i] - '0') % 10;
  }
  return n;
}

int main() {
  string s, t;
  cin >> s;
  rep(i,1,s.size()) t.push_back('9');

  ll n = stoll(s);
  ll ans = 0;
  rep(i,0,t.size()-1) {
    rep(j,0,9) {
      t[i] = j + '0';
      if (stoll(t) <= n) {
        ans = max(ans, f(t));
      }
    }
  }

  cout << ans << endl;
  return 0;
}
