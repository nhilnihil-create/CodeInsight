#include <bits/stdc++.h>

using namespace std;

template<typename T> void drop(const T &x){cout<<x<<'\n';exit(0);}

void milktea() {
  string s;
  cin >> s;
  int a, b, c, d;
  a = s[0] - '0';
  b = s[1] - '0';
  c = s[2] - '0';
  d = s[3] - '0';
  int n = 3;
  string op;
  int ans = a + b + c + d;
  for(int bit = 0; bit < (1<<n); ++bit) {
    op = "+++=";
    ans = a + b + c + d;
    for(int i = 0; i < n; ++i) {
      if(bit & (1<<i)) {
        ans -= 2*(s[i+1] - '0');
        op[i] = '-';
      }
    }
    if(ans == 7) break;
  }
  for(int i = 0; i < n+1; ++i) {
    cout << s[i] << op[i];
  }
  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt=1;
  //cin >> tt;
  while(tt--) milktea();

  return 0;
}
