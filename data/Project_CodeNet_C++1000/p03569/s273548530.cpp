#include <iostream>

using namespace std;

string s;

void solve() {
  int cnt = 0;
  int l = 0, r = s.size() - 1;
  while (l < r) {
    if (s[l] == s[r]) {
      l++;
      r--;
    } else if (s[l] == 'x') {
      cnt++;
      l++;
    } else if (s[r] == 'x') {
      cnt++;
      r--;
    } else {
      cout << -1 << endl;
      return;
    }
  }
  cout << cnt << endl;
}

int main() {
  cin >> s;
  solve();
}
