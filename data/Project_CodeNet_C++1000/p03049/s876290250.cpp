#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n;
  cin >> n;
  vector<string> s(n);
  rep(i, n) cin >> s[i];

  int a = 0, b = 0, ab = 0;
  bool c = true;
  rep(i, n) {
    int l = s[i].size();
    if (s[i][0] == 'B') ++b;
    if (s[i][l-1] == 'A') ++a;
    rep(j, l-1) {
      if (s[i][j] == 'A' && s[i][j+1] == 'B') ++ab;
    }
    if (s[i][0] == 'B' && s[i][l-1] != 'A' ||
        s[i][0] != 'B' && s[i][l-1] == 'A') c = false;
  }
  int ans = ab + min({a, b});
  if (c && a * b > 0) --ans;
  cout << ans << endl;
  return 0;
}