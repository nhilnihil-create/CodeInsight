//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()

int main() {
  string s;
  cin >> s;
  string t = "keyence";
  
  for (int i = 0; i <= 7; i++) {
    bool flag = false;
    string u = t.substr(0, i);
    string v = t.substr(i, 7-i);
    if (s.substr(0, i) == u) {
      flag = true;
    }
    if (s.substr(s.size() - (7-i), 7-i) == v && flag) {
      puts("YES");
      return 0;
    }
  }
  puts("NO");
  return 0;
}