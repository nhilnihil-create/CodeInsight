#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  string s;
  cin >> n >> s;
  string ans = "No";
  int r = 0, b = 0;
  for (int i=0; i<n; i++) {
    if (s[i] == 'R') {
      r += 1;
    }
    else {
      b += 1;
    }
  }

  if (r > b) {
    ans = "Yes";
  }

  cout << ans << endl;
}
