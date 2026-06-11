#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  string s;
  cin >> s;
  int e = 0;
  rep(i, s.size()) if (i % 2 == 0 && s[i] == '1' || i % 2 == 1 && s[i] == '0') ++e;
  int ans = min(e, (int)s.size() - e);
  cout << ans << endl;
  return 0;
}