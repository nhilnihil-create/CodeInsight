#include <bits/stdc++.h>
using namespace std;

int main() {
  string s, t1, t2;
  cin >> s;
  int N = s.size();
  for (int i = 0; i < N; i++) {
    if (s[i] != 'x') t1 += s[i];
  }
  if (t1 == "") {
    cout << 0 << endl;
    return 0;
  }
  t2 = t1;
  reverse(t2.begin(),t2.end());
  if (t1 != t2) {
    cout << -1 << endl;
    return 0;
  }
  int c = 0;
  int n = t1.size();
  int m = (n+1)/2;
  vector<int> countx(m,0);
  for (int i = 0; i < N; i++) {
    if (s[i] != 'x') c += 1;
    else countx[c] += 1;
    if (c == m) break;
  }
  c = 0;
  for (int i = N-1; i > 0; i--) {
    if (s[i] != 'x') c += 1;
    else countx[c] -= 1;
    if (c == m) break;
  }
  int ans = 0;
  for (int e : countx) ans += abs(e);
  cout << ans << endl;
}