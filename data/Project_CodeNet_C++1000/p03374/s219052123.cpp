#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define rep(i,s,e) for(i64 (i) = (s);(i) < (e);(i)++)
#define rev(i,s,e) for(i64 (i) = (s);(i) --> (e);)
#define all(x) x.begin(),x.end()

template<class T>
static inline std::vector<T> ndvec(size_t&& n, T val) noexcept {
  return std::vector<T>(n, std::forward<T>(val));
}

template<class... Tail>
static inline auto ndvec(size_t&& n, Tail&&... tail) noexcept {
  return std::vector<decltype(ndvec(std::forward<Tail>(tail)...))>(n, ndvec(std::forward<Tail>(tail)...));
}

int main() {
  i64 N, C;
  cin >> N >> C;
  vector<i64> X(N), V(N);
  rep(i,0,N) cin >> X[i] >> V[i];

  vector<i64> f1, f2, r1, r2;
  f1.push_back(0);
  f2.push_back(0);
  r1.push_back(0);
  r2.push_back(0);
  {
    i64 sum = 0;
    rep(i,0,N) {
      sum += V[i];
      f1.push_back(std::max(f1.back(), sum - X[i]));
      f2.push_back(std::max(f2.back(), sum - X[i] * 2));
    }
  }
  {
    i64 sum = 0;
    for(i64 i = N; i --> 0;) {
      sum += V[i];
      r1.push_back(std::max(r1.back(), sum - (C - X[i])));
      r2.push_back(std::max(r2.back(), sum - (C - X[i]) * 2));
    }
  }

  i64 MAX = 0;
  for(i64 i = 0;i <= N;i++) {
    MAX = std::max(MAX, f1[i] + r2[N - i]);
    MAX = std::max(MAX, f2[i] + r1[N - i]);
  }
  cout << MAX << endl;
}
