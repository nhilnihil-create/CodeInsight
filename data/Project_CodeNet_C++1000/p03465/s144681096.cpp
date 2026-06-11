#include <bits/stdc++.h>

using namespace std;

int main() {
   ios_base::sync_with_stdio(false);
   int N;
   cin >> N;
   bitset<4000400> dp;
   dp[0] = 1;
   int sum = 0;
   for (int i = 0; i < N; ++i) {
      int x;
      cin >> x;
      sum += x;
      dp |= dp << x;
   }
   int ans = (sum + 1) / 2;
   while (!dp[ans]) ans++;
   cout << ans << "\n";
   return 0;
}
