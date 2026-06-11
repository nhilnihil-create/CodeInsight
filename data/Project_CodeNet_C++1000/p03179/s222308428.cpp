#pragma GCC optimize("Ofast")
#define _USE_MATH_DEFINES
#include "bits/stdc++.h"

using namespace std;

using u8 = uint8_t;
using u16 = uint16_t;
using u32 = uint32_t;
using u64 = uint64_t;
using i8 = int8_t;
using i32 = int32_t;
using i64 = int64_t;
constexpr char newl = '\n';

template<typename T1, typename T2> inline void chmin(T1& a, T2 b) { if (a > b) a = b; }
template<typename T1, typename T2> inline void chmax(T1& a, T2 b) { if (a < b) a = b; }
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define F0R(i,b) FOR(i,0,b)
#define RFO(i,a,b) for (int i = ((b)-1); i >=(a); i--)
#define RF0(i,b) RFO(i,0,b)
//#define F first
//#define S second
#define debug(x) cout << #x << ": " << x << '\n';
template<class T> void Print(vector<T> v) {
  F0R(i, v.size()) {
    cout << v[i] << ' ';
  }
  cout << newl;
}

#if 1

constexpr int MOD = 1e9 + 7; // 1e9 + 7

template<typename F>
struct FixPoint : F {
  FixPoint(F&& f) :F(forward<F>(f)) {}
  template<typename... Args>
  decltype(auto) operator()(Args&&... args) const {
    return F::operator()(*this, forward<Args>(args)...);
  }
};
template<typename F>
inline decltype(auto) MFP(F&& f) {
  return FixPoint<F>{forward<F>(f)};
}

// INSERT ABOVE HERE
signed main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int N;
  cin >> N;

  string s;
  s.reserve(N);
  cin >> s;

  // 狭義単調増加/減少の数列の、両端が一致している、と考える。
  // 4 <>< たとえばこれは、 {1, 3} {3, 2} {2, 4} という3つの数列などが考えられる。
  // 5 <<<< これは {1, 2, 3, 4, 5} 全体で一つの数列。

  // dp[i][j] := i 番目まで決めた時、i 番目の数より大きい、残っている数値の数が j 個のとき

  vector<vector<int>> dp(N + 1, vector<int>(N+1, 0));

  dp[0][0] = 1;

  FOR(i, 0, N - 1) {
    if (s[i] == '<') {
      F0R(j, i + 1) {
        dp[i + 1][j + 1] = dp[i][j] + dp[i + 1][j];
        if (dp[i + 1][j + 1] >= MOD) dp[i + 1][j + 1] -= MOD;
      }
    }
    else {
      F0R(j, i + 1) {
        dp[i + 1][i - j] = dp[i][i - j] + dp[i + 1][i - j + 1];
        if (dp[i + 1][i - j] >= MOD) dp[i + 1][i - j] -= MOD;
      }
    }
  }

  int result = 0;
  F0R(i, N) {
    result += dp[N - 1][i];
    if (result >= MOD) result -= MOD;
  }
  cout << result;
}
#endif
