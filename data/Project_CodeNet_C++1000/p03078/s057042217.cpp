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

  int X, Y, Z, K;
  cin >> X >> Y >> Z >> K;
  vector<i64> as(X), bs(Y), cs(Z);
  F0R(i, X) { cin >> as[i]; }
  F0R(i, Y) { cin >> bs[i]; }
  F0R(i, Z) { cin >> cs[i]; }
  sort(rng(as));
  sort(rng(bs));
  sort(rng(cs));

  // 指定した値以上のB+Cは何通りあるか
  auto hbc = [&](i64 v)->int {
    int r = 0;
    auto cit = lower_bound(rng(cs), v - bs.back());
    RF0(i, Y) {
      while (cit != cs.end() && *cit < v - bs[i]) cit++;
      if (cit == cs.end()) break;
      r += cs.end() - cit;
    }
    return r;
  };

  // 指定した値以上のA+B+Cは何通りあるか
  auto habc = [&](i64 v)->int {
    int r = 0;
    RF0(i, X) {
      int a = hbc(v - as[i]);
      if (!a) break;
      r += a;
      if (r > 10000) break;
    }
    return r;
  };

  i64 thr = 0, rest;
  if ((i64)X * Y * Z >= 10000) {
    i64 l = 0, r = 3e10;
    bool found = false;
    while (r - l > 1) {
      auto mp = (l + r) / 2;
      auto h = habc(mp);
      if (h > 10000) {
        l = mp;
      }
      else if (h < K) {
        r = mp;
      }
      else {
        found = true;
        thr = mp;
        break;
      }
    }
    if (!found) {
      thr = r;
      rest = l;
    }
  }

  vector<i64> rs;
  RF0(a, X) {
    RF0(b, Y) {
      if (as[a] + bs[b] + cs.back() < thr) {
        break;
      }
      RF0(c, Z) {
        if (as[a] + bs[b] + cs[c] < thr) break;
        rs.push_back(as[a] + bs[b] + cs[c]);
      }
    }
  }
  while (rs.size() < K) rs.push_back(rest);
  sort(rrng(rs));
  F0R(i, K) {
    cout << rs[i] << newl;
  }
}
#endif
