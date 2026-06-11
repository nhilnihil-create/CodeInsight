#include <bits/stdc++.h>
using namespace std;

#define int long long

#define ii pair<int,int>
#define fi first
#define sc second

signed main() {
#ifdef _DEBUG
  freopen("in" , "r", stdin );
#endif
  ios::sync_with_stdio(0); cin.tie(0);
  vector<int> a;
  for (char c; cin >> c; a.push_back(c - '0'));
  for (int i = 0; i <= 1; i++)
  for (int j = 0; j <= 1; j++)
  for (int k = 0; k <= 1; k++) {
    int sum = a[0];
    string res; res += char(a[0] + '0');
    if (i) {
      sum += a[1];
      res += '+';
      res += char(a[1] + '0');
    } else {
      sum -= a[1];
      res += '-';
      res += char(a[1] + '0');
    }
    if (j) {
      sum += a[2];
      res += '+';
      res += char(a[2] + '0');
    } else {
      sum -= a[2];
      res += '-';
      res += char(a[2] + '0');
    }
    if (k) {
      sum += a[3];
      res += '+';
      res += char(a[3] + '0');
    } else {
      sum -= a[3];
      res += '-';
      res += char(a[3] + '0');
    }
    if (sum == 7) {
      cout << res << "=7" << '\n';
      return 0;
    }
  }
  return 0;
}
