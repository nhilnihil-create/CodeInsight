#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);

  string s;
  cin >> s;
  
  int n = s.size();
  if (s[0] == '0' || s.back() == '1' || s[n-2] == '0') {
    cout << -1 << '\n';
    return 0;
  }

  for (int i = 0; i < n / 2; ++i) {
    if (s[i] != s[n-2-i]) {
      cout << -1 << '\n';
      return 0;
    }
  }
  
  cout << 1 << " " << 2 << '\n';
  int last = 1;
  for (int i = 1; i < n - 1; ++i) {
    cout << last + 1 << " " << i + 2 << '\n';
    if (s[i] == '1') last = i + 1;
  }
}
