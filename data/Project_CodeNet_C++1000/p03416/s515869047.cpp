#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;

int main() {
  int A, B;
  cin >> A >> B;

  int ans = 0;
  for (int x = A; x <= B; x++) {
    string s = to_string(x);
    if (s[0] == s[4] && s[1] == s[3]) ans += 1;
  }
  cout << ans << endl;
  return 0;
}