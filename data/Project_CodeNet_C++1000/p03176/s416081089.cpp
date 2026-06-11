#include <bits/stdc++.h>
#define dbg(x) cout << #x << ": " << (x) << '\n'
#define ff first
#define ss second
#define ll long long
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;

int main() {
   ios::sync_with_stdio(false);   cin.tie(NULL);   cout.tie(NULL);

   int n;
   cin >> n;
   vector <ll> hgt(n), bty(n), dp(n);
   for (auto &i : hgt)
      cin >> i;
   for (auto &i : bty)
      cin >> i;

   map <int, ll> m;
   m[hgt[0]] = bty[0];
   dp[0] = bty[0];

   ll ans = dp[0];
   for (int i = 1; i < n; i++) {
      auto it = m.upper_bound(hgt[i]);
      dp[i] = bty[i];
      if (it != m.begin()) {
         it--;
         dp[i] += it -> ss;
      }

      it = m.upper_bound(hgt[i]);

      while (it != m.end() && it -> ss <= dp[i]) {
         auto at = it;
         at++;
         m.erase(it);
         it = at;
      }

      m[hgt[i]] = dp[i];
      ans = max(dp[i], ans);
   }

   cout << ans << '\n';

   return 0;
}