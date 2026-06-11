#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  string s, t;
  cin >> s >> t;
  int ls = s.size();
  int lt = t.size();
  vector<string> ss;
  for (int i = 0; i + lt - 1 < ls; ++i) {
    bool ok = true;
    rep(j, lt) {
      if (s[i + j] != '?' && s[i + j] != t[j]) ok = false;
    }
    string u = "";
    rep(j, ls) {
      if (j >= i && j < i + lt) u += t[j-i];
      else if (s[j] == '?') u += 'a';
      else u += s[j];
    }
    if (ok) ss.push_back(u);
  }
  sort(ss.begin(), ss.end());
  if (ss.size() == 0) ss.push_back("UNRESTORABLE");
  cout << ss[0] << endl;
  return 0;
}