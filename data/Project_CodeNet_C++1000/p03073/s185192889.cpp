#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(n, i) for(ll i = 0; i < n; ++i)

void solve(void){
  string s; cin >> s;
  string str1 = "";
  string str2 = "";

  rep((ll)s.size(), i) {
    if (i % 2 == 0) {
      str1 += '0'; str2 += '1';
    } else {
      str1 += '1'; str2 += '0';
    }
  }

  ll res1 = 0, res2 = 0;
  rep((ll)s.size(), i) {
    if (s[i] != str1[i]) ++res1;
    if (s[i] != str2[i]) ++res2;
  }
  cout << min(res1, res2) << endl;
}

int main(void) {
  solve();
  return 0;
}