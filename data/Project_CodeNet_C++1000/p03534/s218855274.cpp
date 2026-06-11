#include <bits/stdc++.h>
using namespace std;

#define fs first
#define sc second
#define pb emplace_back
#define mp make_pair
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()

signed main() {
  int a[3] = {};
  string s;
  cin >> s;
  for (int i = 0; i < s.size(); ++i) {
    a[s[i] - 'a']++;
  }

  sort(a, a + 3);

  a[2] -= a[0];
  a[1] -= a[0];
  a[0] = 0;
  for (int i = 0; i < 3; ++i) {
    if (a[i] >= 2) {
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
}
