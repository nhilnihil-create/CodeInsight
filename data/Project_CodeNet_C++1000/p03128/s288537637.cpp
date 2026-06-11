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

bool lesser(const string& l, const string& r) {
  return l.size() != r.size() ? l.size() < r.size() : l < r;
}

// INSERT ABOVE HERE
signed main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  array<int, 10> ns = { INT32_MAX, 2,5,5,4,5,6,3,7,6 };

  //cout << (lesser("abca","def"));

  int N, M;
  cin >> N >> M;
  vector<int> as(M);
  F0R(i, M) {
    cin >> as[i];
  }

  vector<string> dp(N + 1, "0");
  dp[0] = "";

  F0R(i, N) {
    if (dp[i] == "0") continue;

    F0R(j, M) {
      int n = i + ns[as[j]];
      if (n > N) continue;
      string s = dp[i];
      s.push_back('0' + as[j]);
      if (lesser(dp[n], s)) {
        dp[n] = s;
      }
    }
  }
  cout << dp.back();
}
#endif
