#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const int INF = 1e9;

int main() {
  int n;
  string s;
  cin >> n >> s;
  vector<int> w(n), e(n);
  for (int i = 1; i < n; i++) {
    if (s[i - 1] == 'W')
      w[i] = w[i - 1] + 1;
    else
      w[i] = w[i - 1];
  }

  for (int i = n - 2; i >= 0; i--) {
    if (s[i + 1] == 'E')
      e[i] = e[i + 1] + 1;
    else
      e[i] = e[i + 1];
  }

  int ans = INF;
  rep(i, n) ans = min(ans, w[i] + e[i]);
  cout << ans << endl;
  return 0;
}
