#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for (int i=(a); i<(b); i++)

int main() {
  string S;
  cin >> S;
  int ans = 700;
  FOR(i, 0, 3) {
    if (S[i] == 'o') {
      ans += 100;
    }
  }
  cout << ans << endl;

return 0;
}