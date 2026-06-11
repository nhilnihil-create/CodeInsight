#include <bits/stdc++.h>
using namespace std;
#define ffor(n) for(int i = 0; i < n; i++)
#define fffor(n) for(int j = 0; j < n; j++)
int INF = 1e9 + 7;

int main(void) {
  int n, k;
  cin >> n >> k;
  vector <int> v(n);
  ffor(n) cin >> v[i];
  sort(v.begin(), v.end());
  vector <int> dp(k + 1, 0); // dp[i] is 1 if winning, 2 if losing, 0 if unknown
  for(auto e: v) {
    dp[e] = 1;
  }
  for(int i = 1; i < v[0]; i++) dp[i] = 2;
  for(int i = 1; i <= k; i++) {
    if (dp[i] != 0) continue;
    bool can_force_loss = false;
    for (auto x: v) {
      if (i - x < 0) break;
      if (dp[i - x] == 2) can_force_loss = true;
    }
    if (can_force_loss) dp[i] = 1;
    else dp[i] = 2;
  }
  if (dp[k] == 1) cout << "First\n";
  else cout << "Second\n";
}