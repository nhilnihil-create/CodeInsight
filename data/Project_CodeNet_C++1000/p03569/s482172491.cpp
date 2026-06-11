#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  string s;
  cin >> s;

  string t = "";
  rep(i, s.size()) if (s[i] != 'x') t += s[i];
  bool tp = true;
  rep(i, t.size()) if (t[i] != t[t.size()-1-i]) tp = false;
  if (!tp) {
    cout << -1 << endl;
    return 0;
  }

  vector<int> num_x(t.size()+1, 0);
  int ni = 0;
  rep(i, s.size()) {
    if (s[i] == 'x') ++num_x[ni];
    else ++ni;
  }

  int ans = 0;
  for (int i = 0; i < (int)t.size()-i; ++i) {
    ans += abs(num_x[i] - num_x[t.size()-i]);
  }
  cout << ans << endl;
  return 0;
}