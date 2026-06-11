#pragma GCC optimize("Ofast")
#define _USE_MATH_DEFINES
#include "bits/stdc++.h"

using namespace std;

using u8 = uint8_t;
using u16 = uint16_t;
using u32 = uint32_t;
using u64 = uint64_t;
using i8 = int8_t;
using i16 = int16_t;
using i32 = int32_t;
using i64 = int64_t;

constexpr char newl = '\n';
constexpr double eps = 1e-10;

#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define F0R(i,b) FOR(i,0,b)
#define RFO(i,a,b) for (int i = ((b)-1); i >=(a); i--)
#define RF0(i,b) RFO(i,0,b)
#define fi first
#define se second
#define debug(x) cout << #x << ": " << x << '\n';
#define rng(a) a.begin(),a.end()
#define rrng(a) a.rbegin(),a.rend()

template<typename T1, typename T2> inline void chmin(T1& a, T2 b) { if (a > b) a = b; }
template<typename T1, typename T2> inline void chmax(T1& a, T2 b) { if (a < b) a = b; }
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

  int N, K;
  cin >> N >> K;
  vector<int> vs(N);
  int sum = 0;
  F0R(i, N) {
    cin >> vs[i];
    sum += vs[i];
  }

  int result = 0;

  // i個取り出す
  FOR(i, 1, min(N + 1, K + 1)) {

    int rest = N - i;
    int trash = K - i;

    // 取らない宝石の位置
    F0R(j, i + 1) {

      // restを除き取り出す
      vector<int> as(i);
      if (j) copy(vs.begin(), vs.begin() + j, as.begin());
      if (j + rest < N) copy(vs.begin() + j + rest, vs.end(), as.begin() + j);
      sort(rng(as));
      //Print(as);

      // 戻せるだけ戻す
      int t = min<int>(lower_bound(rng(as), 0) - as.begin(), trash);
      int score = 0;
      FOR(k, t, i) {
        score += as[k];
      }
      chmax(result, score);
    }

  }
  cout << result;
}
#endif
