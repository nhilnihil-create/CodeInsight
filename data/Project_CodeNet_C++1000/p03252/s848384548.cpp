#include <bits/stdc++.h>
using namespace std;

#define debug(x) cerr << #x << ": " << x << endl

int main() {
  ios::sync_with_stdio(false), cin.tie(0);
  string s, t;
  cin >> s >> t;
  map<char, char> mp;
  int n = s.length();
  for (int i = 0; i < n; i++) {
    if (mp.count(s[i]) && mp[s[i]] != t[i]) {
      cout << "No\n";
      return 0;
    }
    mp[s[i]] = t[i];
  }
  for (char c = 'a'; c <= 'z'; c++) {
    for (char d = c + 1; d <= 'z'; d++) {
      if (mp.count(c) && mp.count(d) && mp[c] == mp[d]) {
        cout << "No\n";
        return 0;
      }
    }
  }
  cout << "Yes\n";
  return 0;
}