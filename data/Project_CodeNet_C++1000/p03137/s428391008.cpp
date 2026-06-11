
#include <bits/stdc++.h>
using namespace std;

// syntax sugar: `for (int i = 0; i < N; ++i)`
#define rep(i, N) for (int i = 0; i < (int)(N); ++i)
#define rep2(i, startValue, N) for (int i = (int)(startValue); i < (int)(N); ++i)
// syntax sugar: `for (int i = 0; i < N; ++i)`
#define REP(type, name, beginValue, endCondValue) \
  for (type name = beginValue; name < endCondValue; ++name)
// syntax sugar: 多次元vector
#define VECTOR_DIM3(T, name, d1, d2, d3, initValue) \
    std::vector<std::vector<std::vector<T>>> name(d1, std::vector<std::vector<T>>(d2, std::vector<int>(d3, initValue)));
#define VECTOR_DIM2(T, name, d1, d2, initValue) \
    std::vector<std::vector<T>> name(d1, std::vector<T>(d2, initValue));
#define VECTOR_DIM1(T, name, d1, initValue) \
    std::vector<T> name(d1, initValue);
#define ll long long
#define ld long double
#define DUMP(v) "," #v ":" << v

// ABC117 C - Streamline
int main(){
  int n, m;
  cin >> n >> m;
  vector<int> X(m, 0); // 訪れるべき座標一覧(m個)
  rep(i, m) cin >> X[i];
  sort(X.begin(), X.end());

  ll ans = 0;
  if (n >= m) {
    ans = 0; // 最初にコマを置いた時点でクリア
  } else {
    // 数直線上の隣り合う点同士を結ぶ線分を大きい順に並べ、
    // N-1回分断すると、N個の区間ができ、それが答え
    vector<int> diff(m-1,0);
    int base = X[0];
    rep2(i,1,m) {
      diff[i-1] = X[i] - base;
      base = X[i];
    }
    // 大きい順にN-1個の線分をスキップし、残りを合計
    sort(diff.begin(), diff.end(), greater<int>());
    ans = accumulate(diff.begin() + (n-1), diff.end(),0LL);
  }

  cout << ans << endl;
  return 0;
}
