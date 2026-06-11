#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < (b); i++)
#define rrep(i, a, b) for (int i = a; i >= (b); i--)
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
template <class T>
inline bool chmin(T& a, T b) {
   if (a > b) {
      a = b;
      return true;
   }
   return false;
}
template <class T>
inline bool chmax(T& a, T b) {
   if (a < b) {
      a = b;
      return true;
   }
   return false;
}
void hr() {
   cerr << "--------------" << endl;
}
const int INF = 1001001001;
const int MOD = 1000000007;

ll dp[50][2];
int main() {
   cin.tie(0);
   ios_base::sync_with_stdio(0);

   int n;
   ll k;
   cin >> n >> k;
   vector<ll> a(n);
   rep(i, 0, n) cin >> a[i];
   rep(i, 0, 50) dp[i][0] = dp[i][1] = -1;

   dp[45][0] = 0;
   rrep(d, 44, 0) {
      ll bitk = 1LL << d;

      int cnt = 0;
      rep(i, 0, n) if (a[i] & bitk) cnt++;
      if (dp[d + 1][1] >= 0) {
         chmax(dp[d][1], dp[d + 1][1] + bitk * max(cnt, n - cnt));
      }

      if (dp[d + 1][0] >= 0) {
         if (bitk & k) {
            chmax(dp[d][1], dp[d + 1][0] + bitk * cnt);
            chmax(dp[d][0], dp[d + 1][0] + bitk * (n - cnt));

         } else {
            chmax(dp[d][0], dp[d + 1][0] + bitk * cnt);
         }
      }
   }
   cout << max(dp[0][0], dp[0][1]) << endl;
   return 0;
}