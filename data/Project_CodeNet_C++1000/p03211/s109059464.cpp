#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;

int main() {
  string S;
  cin >> S;

  int ans = INT_MAX;
  rep(i, S.size() - 2) { ans = min(ans, abs(stoi(S.substr(i, 3)) - 753)); }
  cout << ans << endl;
  return 0;
}