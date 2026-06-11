#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string S;
  cin >> S;
  int res = 0;
  for (int i = 0; i < (int)S.size(); i++) {
    res += S[i] - '0';
  }
  res = max(res, (S[0] - '0' - 1) + 9 * ((int)S.size() - 1));
  cout << res << '\n';
  return 0;
}
