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
  string S;
  cin >> N >> K >> S;
  vector<int> as, bs; // 1, 0
  int a = 0;
  if (S.front() == '0') as.push_back(0);
  S += "10";
  F0R(i, S.size()) {
    if (!i || S[i] == S[i-1]) {
      a++;
    }
    else {
      if (S[i-1] == '0') {
        bs.push_back(a);
      }
      else {
        as.push_back(a);
      }
      a = 1;
    }
  }
  as.back()--;
  //Print(as);
  //Print(bs);
  int b = min<int>(K + 1, as.size());
  a = 0;
  F0R(i, b) {
    if (i) a += bs[i - 1];
    a += as[i];
  }
  int result = a;
  F0R(i, as.size() - b) {
    a += as[b + i] - as[i] + bs[b+i-1] - bs[i];
    chmax(result, a);
  }
  cout << result;
}
#endif
