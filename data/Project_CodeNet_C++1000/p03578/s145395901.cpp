#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  map<int, int> mp;
  for (int i = 0; i < n; i++) {
    int d;
    cin >> d;
    mp[d]++;
  }

  int m;
  cin >> m;
  bool ok = true;
  for (int i = 0; i < m; i++) {
    int t;
    cin >> t;
    if (mp.count(t) && mp[t] > 0) {
      mp[t]--;
    } else {
      ok = false;
      break;
    }
  }

  if (ok)
    puts("YES");
  else
    puts("NO");

  return 0;
}