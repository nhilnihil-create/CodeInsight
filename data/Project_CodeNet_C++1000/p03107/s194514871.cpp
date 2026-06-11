#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(n, i) for(ll i = 0; i < n; ++i)

void solve(void){
  string s; cin >> s;

  ll r = 0, b = 0;
  rep((ll)s.size(), i) {
    if (s[i] == '0') ++r;
    else ++b;
  }

  cout << min(r, b) * 2 << endl;
}

int main(void) {
  solve();
  return 0;
}
