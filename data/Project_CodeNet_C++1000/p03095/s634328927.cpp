#include <bits/stdc++.h>

using namespace std;

typedef long long llint;
const long long MOD = 1e9 + 7;

int main() {
  int n;
  string s;
  cin >> n >> s;

  llint ans = 1;
  vector<llint> used(26, 0);
  for (int i = 0; i < n; i++) {
    int d = s[i] - 'a';
    used[d]++;
  }
  for (int i = 0; i < 26; i++) {
    if (used[i] == 0) continue;
    ans *= used[i] + 1;
    ans %= MOD;
  }

  cout << ans - 1 << endl;

  return 0;
}