#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F first
#define S second
#define pii pair<int, int>
#define eb emplace_back
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep3(i, l, n) for (int i = l; i < (n); ++i)
#define sz(v) (int)v.size()
const int inf = 1e9 + 7;
const ll INF = 1e18;
#define abs(x) (x >= 0 ? x : -(x))
#define lb(v, x) (int)(lower_bound(all(v), x) - v.begin())
#define ub(v, x) (int)(upper_bound(all(v), x) - v.begin())
template<typename T1, typename T2> inline bool chmin(T1 &a, T2 b) { if (a > b) { a = b; return 1; } return 0; }
template<typename T1, typename T2> inline bool chmax(T1 &a, T2 b) { if (a < b) { a = b; return 1; } return 0; }
template<typename T> T gcd(T a, T b) { if (b == 0) return a; return gcd(b, a % b); }
template<typename T> T lcm(T a, T b) { return a / gcd(a, b) * b; }
template<typename T> T pow(T a, int b) { return b ? pow(a * a, b / 2) * (b % 2 ? a : 1) : 1; }
const int mod = 1000000007;
ll modpow(ll a, int b) { return b ? modpow(a * a % mod, b / 2) * (b % 2 ? a : 1) % mod : 1; }
template<class T> ostream& operator<<(ostream& os, const vector<T>& vec) { for (auto &vi: vec) os << vi << " "; return os; }
template<class T, class U> ostream& operator<<(ostream& os, const pair<T, U>& p) { os << p.F << " " << p.S; return os; }
template<class T> inline void add(T &a, int b) { a += b; if (a >= mod) a -= mod; }



void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(10);

    int T;
    // cin >> T;
    T = 1;

    while (T--) {
        solve();
    }
}

// https://atcoder.jp/contests/dp/submissions/10212135
void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;

  // dp[i][j] : 最後の値が j
  // これまで選んだ数全部を持たないとダメ

  // i 番目の数より大きいのが j 個残ってるような場合の数
  vector<vector<int> > dp(n + 1, vector<int>(n));
  dp[0] = vector<int>(n, 1);
  // dp[0][0] : 0 番目 n-1

  rep3(i, 1, n) {
    vector<int> acc(n + 1);
    rep(j, n) {
      if (s[i - 1] == '<') {
        (acc[0] += dp[i - 1][j]) %= mod;
        (acc[j] += mod - dp[i - 1][j]) %= mod;
      } else {
        int tmp = n - i - j; // ai より小さいのの個数
        (acc[j] += dp[i - 1][j]) %= mod;
        (acc[j + tmp] += mod - dp[i - 1][j]) %= mod;
      }
    }
    rep3(j, 1, n) (acc[j] += acc[j - 1]) %= mod;
    rep(j, n) add(dp[i][j], acc[j]);
  }

  cout << dp[n - 1][0] << endl;
  // rep(i, n) cout << dp[i] << endl;
}
