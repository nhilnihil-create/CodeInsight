#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;
int main() {
  string s;
  cin >> s;
  int n = s.size();
  int cnt = 0;
  for (int i = 1; i < n; i++) {
    if (i > s.size()) {
      break;
    }
    if (s[i-1] == 'B' && s[i] == 'C') {
      s = s.erase(i-1,1);
      s[i-1] = 'D';
      cnt++;
    }
  }
  n = s.size();
  int R[n];
  for (int i = 0; i < n; i++) {
    if (i == 0) {
      if (s[0] == 'A') {
        R[0] = 1;
      } else {
        R[0] = 0;
      }
    } else {
      if (s[i] == 'A') {
        R[i] = R[i-1] + 1;
      } else if (s[i] == 'D') {
        R[i] = R[i-1];
      } else {
        R[i] = 0;
      }
    }
  }
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'D') {
      ans += R[i];
    }
  }
  cout << ans << endl;
  return 0;
}