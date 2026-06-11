#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n;
  string s;
  cin >> n >> s;
  int lb = 0, rw = 0;
  rep(i, n) if (s[i] == '.') ++rw;
  int ans = rw;
  rep(i, n) {
    if (s[i] == '#') ++lb;
    else --rw;
    ans = min(ans, lb + rw);
  }
  cout << ans << endl;
  return 0;
}