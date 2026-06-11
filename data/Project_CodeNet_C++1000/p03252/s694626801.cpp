#include <bits/stdc++.h>
using namespace std;

// ----------- define --------------
#define int long long
#define vi vector<int>
#define vc vector<char>
#define mii map<int,int>
#define ii pair<int,int>
#define fi first
#define sc second
#define all(x) (x).begin(),(x).end()
#define get_bit(x, k) ((x >> k) & 1)
// ---------------------------------

void MAIN() {
  string s, t;
  cin >> s >> t;
  map<char, char> m, r;
  for (int i = 0; i < s.size(); i++) {
    if (m.count(s[i]) && m[s[i]] != t[i]) {
      cout << "No" << '\n';
      return;
    }
    m[s[i]] = t[i];
    if (r.count(t[i]) && r[t[i]] != s[i]) {
      cout << "No" << '\n';
      return;
    }
    r[t[i]] = s[i];
  }
  for (char i = 'a'; i <= 'z'; i++) {
    if (!m.count(i)) continue;
    vector<int> v(256);
    char j = i;
    do {
      if (v[j]) {
        cout << "No" << '\n';
        return;
      }
      v[j] = 1;
      if (!m.count(j)) break;
      j = m[j];
    } while (j != i);
  }
  cout << "Yes" << '\n';
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T = 1;
  // cin >> T;
  while (T--) MAIN();
}
