#include <bits/stdc++.h>

using namespace std;

using ll = long long;
const ll INF = 1e18;

int main() {
   ios_base::sync_with_stdio(false);
   int N; ll tol, tor;
   cin >> N >> tor >> tol;
   vector<int> P(N + 2);
   for (int i = 1; i <= N; ++i) {
      cin >> P[i];
   }
   P[0] = 0;
   P[N + 1] = N + 1;
   vector<ll> dp(N + 2, INF);
   dp[0] = 0;
   for (int i = 1; i <= N + 1; ++i) {
      int cnt = 0;
      for (int j = i - 1; j >= 0; --j) {
         if (P[j] > P[i]) {
            cnt++;
         } else {
            dp[i] = min(dp[i], dp[j] + tor * cnt + tol * (i - j - 1 - cnt));
         }
      }
   }
   cout << dp[N + 1] << "\n";
   return 0;
}
