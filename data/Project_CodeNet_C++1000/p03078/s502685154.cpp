#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  int X, Y, Z, K;
  cin >> X >> Y >> Z >> K;
  vector<int64_t> A(X);
  rep(i, X) cin >> A[i];
  vector<int64_t> B(Y);
  rep(i, Y) cin >> B[i];
  vector<int64_t> C(Z);
  rep(i, Z) cin >> C[i];

  vector<int64_t> AB(X * Y);
  rep(i, X) rep(j, Y) AB[i * Y + j] = A[i] + B[j];
  sort(AB.rbegin(), AB.rend());

  int KXY = min(K, X * Y);
  vector<int64_t> ABC(KXY * Z);
  rep(i, KXY) {
    rep(j, Z) { ABC[i * Z + j] = AB[i] + C[j]; }
  }
  sort(ABC.rbegin(), ABC.rend());
  rep(i, K) { cout << ABC[i] << endl; }
  return 0;
}
