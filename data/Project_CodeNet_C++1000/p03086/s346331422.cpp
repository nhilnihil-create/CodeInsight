#include <bits/stdc++.h>
using namespace std;

template<typename T> void drop(const T &x){cout<<x<<'\n';exit(0);}

bool check(char c) {
  if(c == 'A') return true;
  if(c == 'C') return true;
  if(c == 'G') return true;
  if(c == 'T') return true;
  return false;
}

void solve() {
  string s;
  cin >> s;

  int ans = 0;
  for(int i = 0; i < s.size(); ++i) {
    if(check(s[i])) {
      int count = 0;
      for(int j = i; j < s.size(); ++j) {
        if(!check(s[j])) break;
        count++;
      }
      ans = max(ans, count);
    }
  }
  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T=1;
  //cin >> T;
  while(T--) solve();

  return 0;
}
