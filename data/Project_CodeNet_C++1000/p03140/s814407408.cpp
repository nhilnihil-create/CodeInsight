#include <bits/stdc++.h>
using namespace std;
#define rep(i, m, n) for (int i = m; i < n; ++i)
#define rem(i, m, n) for (int i = m; i >= n; --i)
typedef long long ll;
#define mod 1000000007
template<class T>bool chmax(T &a, const T &b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b < a) { a = b; return 1; } return 0; }

int main() {
  int N; cin >> N;
  string s[3];
  rep(i, 0, 3) cin >> s[i];
  int ans = 0;
  rep(i, 0, N) {
    int cnt = 0;
    if(s[0][i] == s[1][i]) {
      if(s[0][i] != s[2][i]) ans++;
    } else {
      if(s[0][i] != s[2][i] && s[1][i] != s[2][i]) ans += 2;
      else ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
