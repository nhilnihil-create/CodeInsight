#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  string s;
  cin >> s;
  int rbc = 0;
  ll ans = 0;
  for (int i = s.size()-2; i >= 0; --i) {
    if (s[i] == 'A' && (s[i+1] == 'A' || s[i+1] == 'B')) {
      ans += rbc;
      continue;
    }
    if (s[i] == 'B' && s[i+1] == 'C') {
      ++rbc;
      continue;
    }
    if (s[i] == 'C' && (s[i+1] == 'A' || s[i+1] == 'B')) continue;
    rbc = 0;
  }
  cout << ans << endl;
  return 0;
}