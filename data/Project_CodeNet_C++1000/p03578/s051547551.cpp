#define _GIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
const double EPS = 1e-10;


int main(void) {
  ll N, M;
  cin >> N;
  vector<ll> D(N);
  rep(i, N) cin >> D[i];
  cin >> M;
  vector<ll> T(M);
  rep(i, M) cin >> T[i];

  // 対応する点数の問題があるかどうかなので
  //  ソートしてから前から調べる
  // Mapでもいいかも
  sort(D.begin(), D.end());
  sort(T.begin(), T.end());
  int d = 0;
  int t = 0;
  while (t < M && d < N) {
    if (T[t] < D[d]) break;
    if (T[t] == D[d]) {
      ++t;
    }
    ++d;
  }

  if (t == M) cout << "YES" << endl;
  else cout << "NO" << endl;
  
  return 0;
}