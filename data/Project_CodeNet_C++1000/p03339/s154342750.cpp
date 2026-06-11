#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int ans = 0;
  for (int i=1; i<n; i++) {
    if (s[i] == 'E') ans++;      
  }
  int temp = ans;
  for (int i=1; i<n; i++) {
    if (s[i] == 'E') temp--;
    if (s[i-1] == 'W') temp++;
    if (temp < ans) ans = temp;
  }
  cout << ans << '\n';
  return 0;
}