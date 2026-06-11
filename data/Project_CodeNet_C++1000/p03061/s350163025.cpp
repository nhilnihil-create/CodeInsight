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

i64 gcd(i64 a, i64 b) { return b ? gcd(b, a % b) : a; }

// INSERT ABOVE HERE
signed main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int N;
  cin >> N;
  vector<int> as(N), ls(N), rs(N);
  F0R(i, N) {
    cin >> as[i];
    if (!i) {
      ls[i] = as[i];
    }
    else {
      ls[i] = gcd(ls[i - 1], as[i]);
    }
  }
  RF0(i, N) {
    if (i == N - 1) {
      rs[i] = as[i];
    }
    else {
      rs[i] = gcd(rs[i + 1], as[i]);
    }
  }
  int result = 0;
  F0R(i, N) {
    if (!i) {
      chmax(result, rs[1]);
    }
    else if (i == N - 1) {
      chmax(result, ls[N - 2]);
    }
    else {
      chmax(result, gcd(ls[i - 1], rs[i + 1]));
    }
  }
  cout << result;
}
#endif
