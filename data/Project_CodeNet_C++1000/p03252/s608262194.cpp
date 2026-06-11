#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  string s, t;
  cin >> s >> t;

  auto convert = [&](string u) {
    char c = 'a';
    map<char, char> mp;
    rep(i, u.size()) {
      if (!mp[u[i]]) {
        mp[u[i]] = c;
        u[i] = c;
        c++;
      } else {
        u[i] = mp[u[i]];
      }
    }
    return u;
  };

  cout << (convert(s) == convert(t) ? "Yes" : "No") << endl;
  return 0;
}
