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

  int A, B, Q;
  cin >> A >> B >> Q;
  vector<i64> as(A+2), bs(B+2);
  F0R(i, A) { cin >> as[i+1]; }
  F0R(i, B) { cin >> bs[i+1]; }
  as[0] = bs[0] = -1e12;
  as.back() = bs.back() = 1e12;
  F0R(i, Q) {
    i64 x; cin >> x;
    auto ar = lower_bound(rng(as), x), br = lower_bound(rng(bs), x);
    auto al = ar - 1, bl = br - 1;
    i64 res = min(x - min(*al, *bl), max(*ar, *br) - x);
    i64 l = *br - x, r = x - *al;
    chmin(res, min(l, r)+l+r);
    l = *ar - x; r = x - *bl;
    chmin(res, min(l, r) + l + r);
    cout << res << newl;
  }
}
#endif
