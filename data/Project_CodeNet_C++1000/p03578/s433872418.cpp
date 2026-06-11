//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()


int main() {
  int n;
  cin >> n;
  vector<int> d(n);
  rep(i, n) cin >> d[i];
  int m;
  cin >> m;
  vector<int> t(m);
  bool flag = true;
  rep(i, m) cin >> t[i];
  sort(all(d));
  sort(all(t));
  int p = 0;
  rep(i, m) {
    for (int j = p; j < n; j++) {
      if (d[j] == t[i]) {
        p = j+1;
        break;
      }
      else if (d[j] > t[i]) {
        p = j;
        flag = false;
      }
    }
  }
  if (flag) puts("YES");
  else puts("NO");
  return 0;
}