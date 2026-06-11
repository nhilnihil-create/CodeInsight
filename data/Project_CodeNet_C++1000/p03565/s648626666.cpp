#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
#define repr(i, n) for(int i = n; i >= 0; i--)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
int main()
{
  string s, t;
  cin >> s >> t;
  int cnt = 0;
  vector<string> items;  
  rep(i, s.size()) {
    if (s[i] == t[0] || s[i] == '?') {
      bool ok = true;
      for (int j = 0; j < t.size(); j++) {
        if (i+j >= s.size()) {
          ok = false;
          break;
        }
        if (s[i+j] == t[j] || s[i+j] == '?') continue;
        ok = false;
      }
      if (ok) {
        string c = "";
        rep(j, s.size()) {
          c += s[j];
        }
        rep(j, t.size()) c[i+j] = t[j];
        rep(j, s.size()) {
          if (c[j] == '?') c[j] = 'a';
        }
        items.push_back(c);
      }
    }
  }
  if (items.size()) {
    sort(items.begin(), items.end());
    cout << items[0] << endl;
  } else {
    cout << "UNRESTORABLE" << endl;
  }
  return 0;
}