#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define F first
#define S second

const int maxN = 1e5;
const int inf = 0x3f3f3f3f;
typedef long long ll;

int k;
int dp[maxN];

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//  freopen("abc.inp", "r", stdin); freopen("abc.out", "w", stdout);
  cin >> k;

  queue< pii > q;
  memset(dp, inf, sizeof dp);

  for (int d = 1; d < 10; ++d) {
    dp[d % k] = min(dp[d % k], d);
    q.push({d, d % k});
  }

  while (!q.empty()) {
    pii t = q.front(); q.pop();
    int du = t.S, min_sum = t.F;
    if (min_sum > dp[du]) continue;

    for (int d = 0; d < 10; ++d) {
      int new_du = (du * 10 + d) % k;

      if (dp[new_du] > dp[du] + d) {
        dp[new_du] = dp[du] + d;
        q.push( {dp[new_du], new_du});
      }
    }
  }

  cout << dp[0];
  return 0;
}
