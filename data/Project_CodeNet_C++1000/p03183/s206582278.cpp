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


// INSERT ABOVE HERE
signed main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int N;
  cin >> N;

  struct Block {
    int w, s, v;
  };

  vector<Block> bs(N);
  FOR(i, 0, N) {
    cin >> bs[i].w >> bs[i].s >> bs[i].v;
  }

  sort(bs.begin(), bs.end(), [](const Block& l, const Block& r)->bool {
    return l.w + l.s < r.w + r.s;
    });

  const int smax = 1e4 * 2 + 1;

  // dp[i][j] := 下から i個詰んだとき、残り詰める重さが[j]の時の価値の総和の最大値
  // ... それだと既に使ったブロックが状態に入っていない...

  // dp[i][j] := 上から i個詰んだとき、既に詰まれた重さが[j]の時の価値の総和の最大値
  // ... 同上...

  // dp[i][j][k] := j 番目までのブロックを使うか使わないかして 上から i個詰んだとき、
  // 既に詰まれた重さが[k]の時の（略）
  // dp[i][j][k] = max(dp[i][j-1][k], dp[i-1][j-1][k-w[j]] + v[j] when k-w[j] <= s[j])
  // ... この式だと [j] の計算に [j-1] しか使えてないから、たとえば
  // 2番目ブロック→1番目ブロックの順に置く方法が探索できていない。

  // snukeさんの解説読む...

  // dp[i][j] := i 番目までのブロック（全て使わなくてもいい）で積むとき、重さ j 以下での価値の総和の最大

  // 既に上に詰んである重さを C として、i と j 2つを下に積むとき
  // C + wj <= si (jを上に積める条件)
  // C + wi <= sj (iを上に積める条件)
  // C を最大化したい場合、si - wj > sj - wi のとき j を上に積むべき
  // 式変形すると si + wi > sj + wj のとき j が上。
  // つまり全要素を予め s + w で昇順ソートしておけば、順に使っていくのが最適となる

  vector<vector<i64>> dp(2, vector<i64>(smax));

  FOR(i, 0, N) {

    Block& b = bs[i];

    FOR(j, 1, b.w) {
      dp[1][j] = dp[0][j];
    }
    FOR(j, b.w, min(b.w+b.s+1,smax)) {
      dp[1][j] = max(dp[0][j], dp[0][j - b.w] + b.v);
    }
    FOR(j, b.w + b.s + 1, smax) {
      dp[1][j] = dp[0][j];
    }

    swap(dp[0], dp[1]);
  }

  i64 result = 0;
  F0R(i, smax) {
    chmax(result, dp[0][i]);
  }
  cout << result;
}
#endif
