#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
const ll M = 1e9 + 7;

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;

  int r = 0;
  int l = 0;
  
  bool flag = true;
  rep(i,n-1) if (s[i] != s[i+1]) flag = false;
  if (flag) {
    cout << 0 << endl;
    return 0;
  }

  rep(i,n) if (s[i] == '.') r++;
  int ans = r;
  rep(i,n) {
    if(s[i] == '#') {
      l++;
    } else {
      r--;
    }
    ans = min(ans,l+r);
  }
  cout << ans << endl;
  return 0;
}