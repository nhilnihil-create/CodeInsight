#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int l = 0, r = 0;
  rep(i,n) {
    if (s[i] == '.') r++;
  }
  int ans = l+r;
  rep(i,n) {
    if(s[i] == '#') {
      l++;
    } else {
      r--;
    }
    ans = min(ans, l+r);
  }
  cout << ans << endl;
  return 0;
}