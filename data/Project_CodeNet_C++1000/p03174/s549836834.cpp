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
// const int MOD = 998244353;

ll dp[1 << 22];
int a[25][25];
int main() {
   cin.tie(0);
   ios_base::sync_with_stdio(0);

   int n;
   cin >> n;
   rep(i, 0, n) rep(j, 0, n) cin >> a[i][j];

   dp[0] = 1;
   rep(S, 1, 1 << n) {
      int i = __builtin_popcount(S);
      rep(j, 0, n) if ((S >> j) & 1 &&
                       a[i - 1][j] == 1)(dp[S] += dp[S ^ (1 << j)]) %= MOD;
   }
   ll ans = dp[(1 << n) - 1];
   cout << ans << endl;
   return 0;
}