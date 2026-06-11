#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;

int main() {
  string S;
  cin >> S;

  int cnt = 0;
  int ans = 0;
  rep(i, S.size()) {
    if (S[i] == 'A' || S[i] == 'C' || S[i] == 'G' || S[i] == 'T')
      cnt++;
    else {
      ans = max(ans, cnt);
      cnt = 0;
    }
  }
  ans = max(ans, cnt);
  cout << ans << endl;
  return 0;
}