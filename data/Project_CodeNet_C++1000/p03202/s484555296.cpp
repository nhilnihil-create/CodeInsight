#include <bits/stdc++.h>
// #include <atcoder/all>
using namespace std;
// using namespace atcoder;
template <class T, class U>
ostream &operator<<(ostream &os, const pair<T, U> &p) {
  os << "(" << p.first << "," << p.second << ")";
  return os;
}
#ifdef __LOCAL
#define debug(x) cerr << __LINE__ << ": " << #x << " = " << (x) << '\n'
#define debugArray(x, n)                                      \
  cerr << __LINE__ << ": " << #x << " = {";                   \
  for (long long hoge = 0; (hoge) < (long long)(n); ++(hoge)) \
    cerr << ((hoge) ? "," : "") << x[hoge];                   \
  cerr << "}" << '\n'
#define debugMatrix(x, h, w)                                         \
  cerr << __LINE__ << ": " << #x << " =\n";                          \
  for (long long hoge = 0; (hoge) < (long long)(h); ++(hoge)) {      \
    cerr << ((hoge ? " {" : "{{"));                                  \
    for (long long fuga = 0; (fuga) < (long long)(w); ++(fuga))      \
      cerr << ((fuga ? ", " : "")) << x[hoge][fuga];                 \
    cerr << "}" << (hoge + 1 == (long long)(h) ? "}" : ",") << '\n'; \
  }
#else
#define debug(x) (void(0))
#define debugArray(x, n) (void(0))
#define debugMatrix(x, h, w) (void(0))
#endif

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  int N;
  cin >> N;
  int A[N];
  for (int i = 0; i < N; i++) cin >> A[i];
  bool inc = true;
  for (int i = 0; i + 1 < N; i++) inc &= A[i] < A[i + 1];
  if (inc) {
    cout << 1 << '\n';
  } else {
    int ok = N, ng = 1;
    while (abs(ok - ng) > 1) {
      int K = (ok + ng) / 2;
      stack<pair<int, int>> S;
      auto check = [&]() {
        for (int i = 1; i < N; i++) {
          if (A[i - 1] >= A[i]) {
            while (!S.empty() && S.top().first > A[i]) S.pop();
            if (S.empty() || S.top().first < A[i]) S.push({A[i], 0});
            int back = A[i];
            while (back > 0 && S.top().second == K - 1) {
              S.pop();
              back--;
              if (back == 0) return false;
              if (S.empty() || S.top().first < back) S.push({back, 0});
            }
            auto p = S.top();
            S.pop();
            S.push({p.first, p.second + 1});
          }
        }
        return true;
      };
      if (check()) {
        ok = K;
      } else {
        ng = K;
      }
    }
    cout << ok << '\n';
  }
  return 0;
}
