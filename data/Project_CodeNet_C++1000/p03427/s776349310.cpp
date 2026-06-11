#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
const int INF = 1e9;

int main() {
  string s;
  cin >> s;
  int n = s.size();
  bool nine = true;
  for (int i = 1; i < n; ++i) {
    if (s[i] == '9')
      continue;
    else
      nine = false;
  }
  int ans = s[0] - '0' + 9 * (n - 1);
  cout << (nine ? ans : ans - 1) << endl;
  return 0;
}
