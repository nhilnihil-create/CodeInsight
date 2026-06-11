#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(), (x).end()
template<typename T> inline bool chmax(T &a, T b) { if (a < b) { a = b; return true; } return false; }


int main() {
  int N; cin >> N;
  vector<array<int, 3>> abc(N);
  rep(i, N) cin >> abc[i][0] >> abc[i][1] >> abc[i][2];

  vector<array<int, 3>> dp(N+1);
  rep(i, N) rep(j, 3) rep(k, 3) {
    if (j == k) continue;
    chmax(dp[i+1][k], dp[i][j] + abc[i][k]);
  }

  int ans = *max_element(all(dp[N]));
  cout << ans << '\n';
}
