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

  int N, A, B, C;
  cin >> N >> A >> B >> C;
  vector<int> ls(N);
  F0R(i, N) {
    cin >> ls[i];
  }
  sort(rrng(ls));
  i64 best = 1e9;
  // pow(4,N)
  F0R(bits, 1 << (N * 2)) {
    i64 mp = 0;
    int a = 0, b = 0, c = 0;
    F0R(i, N) {
      switch ((bits >> (i * 2)) & 3) {
      case 1:
        if (a) mp += 10;
        a += ls[i];
        break;
      case 2:
        if (b) mp += 10;
        b += ls[i];
        break;
      case 3:
        if (c) mp += 10;
        c += ls[i];
        break;
      }
    }
    if (!a || !b || !c) continue;
    mp += abs(A - a) + abs(B - b) + abs(C - c);
    chmin(best, mp);
  }
  cout << best;
}
#endif
