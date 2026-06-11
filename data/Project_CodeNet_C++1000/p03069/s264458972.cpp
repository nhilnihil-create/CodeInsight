#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
const int INF = 1e9;

int main() {
  ll n, ans = INF, cnt = 0;
  string s;
  cin >> n >> s;
  vector<ll> w(n + 3, 0), b(n + 3, 0);
  for (int i = 0; i < n; ++i) {
    if (s[i] == '.') {
      w[i + 1] = w[i] + 1;
      b[i + 1] = b[i];
    } else {
      w[i + 1] = w[i];
      b[i + 1] = b[i] + 1;
    }
  }

  for (int i = 0; i <= n; ++i) 
    ans = min(ans, b[i] + w[n] - w[i]);
  

  cout << ans << endl;
  return 0;
}
