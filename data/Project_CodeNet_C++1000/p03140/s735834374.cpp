#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
using namespace std;
using ll = long long;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n;
  string a, b, c;
  cin >> n >> a >> b >> c;
  int ans = 0;
  for(int i = 0; i < n; i++) {
    set<char> tmp;
    tmp.insert(a[i]);
    tmp.insert(b[i]);
    tmp.insert(c[i]);
    if(tmp.size() == 1) continue;
    if(tmp.size() == 2) {
      ans += 1;
      continue;
    }
    if(tmp.size() == 3) { ans += 2; }
  }
  cout << ans << endl;

  return 0;
}