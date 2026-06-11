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

#ifdef __GNUC__
// __builtin_popcount
// __builtin_popcountl
// __builtin_popcountll
constexpr auto popcount = __builtin_popcount;
#endif

// 一番右端の立っているビット位置を求める
// https://siokoshou.hatenadiary.org/entry/20090704/p1
struct GetNumberOfTrailingZeros {
  constexpr GetNumberOfTrailingZeros() : table() {
    uint64_t hash = 0x03F566ED27179461UL;

    for (int i = 0; i < 64; i++)
    {
      table[hash >> 58] = i;
      hash <<= 1;
    }
  }
  int Calc(int64_t x)
  {
    if (x == 0) return 64;

    uint64_t y = (uint64_t)(x & -x);
    int i = (int)((y * 0x03F566ED27179461UL) >> 58);
    return table[i];
  }
  int table[64];
};

#if 1

// INSERT ABOVE HERE
signed main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  GetNumberOfTrailingZeros gntz;

  int N;
  cin >> N;

  vector<i64> dp(1 << N, INT64_MIN);
  vector<i64> scores(1 << N, -1);

  dp[0] = scores[0] = 0;
  F0R(i, N) {
    int n = 1 << i;
    dp[n] = scores[n] = 0;
    F0R(j, N) {
      cin >> scores[n | (1 << j)];
    }
  }

  F0R(i, 1 << N) {
    if (scores[i] < 0) {

      int n = 1 << gntz.Calc(i);
      int b = i & ~n;
      i64 score = scores[b];

      FOR(j, 1, 99) {
        b >>= 1;
        if (b & 1) {
          score += scores[n | (1 << j)];
        }
      }
      scores[i] = score;
    }
  }

  auto dfs = [&](auto dfs, u16 U)->i64 {
    if (dp[U] > INT64_MIN) return dp[U];

    // 部分集合 U の部分集合を全て列挙
    // https://qiita.com/drken/items/7c6ff2aa4d8fce1c9361
    // ↑の#7

    i64 result = 0;

    for (int bit = U; bit; bit = (bit - 1) & U) {

      i64 score = scores[bit] + dfs(dfs, ~bit & U);
      chmax(result, score);
    }

    return dp[U] = result;
  };
  auto result = dfs(dfs, (1 << N) - 1);
  cout << result;
}
#endif
