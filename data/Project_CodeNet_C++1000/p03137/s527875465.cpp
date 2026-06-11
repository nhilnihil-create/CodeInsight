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
  int N, M;
  cin >> N >> M;
  vector<int> X(M);
  rep(i, M) cin >> X[i];

  if (N >= M) {
    cout << 0 << endl;
    return 0;
  }

  sort(X.begin(), X.end());
  vector<int> L(M - 1, 0);
  rep(i, M - 1) {
    L[i] = X[i + 1] - X[i];
  }

  sort(L.rbegin(), L.rend());
  ll num = 0;
  rep(i, N - 1) num += L[i];

  cout << X[M - 1] - X[0] - num << endl;
  
  return 0;
}