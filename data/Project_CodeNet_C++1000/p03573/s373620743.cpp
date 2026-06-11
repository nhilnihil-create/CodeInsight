#include <bits/stdc++.h>
#define rep2(i, m, n) for (int i = (int)(m); i < (int)(n); i++)
#define rep(i, n) rep2(i, 0, n)
#define all(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
using namespace std;
using ll = long long;
template <typename T>
T sq(T x) {
  return x * x;
}

signed main() {
  int A, B, C;
  cin >> A >> B >> C;
  if (A == B)
    cout << C << endl;
  else if (A == C)
    cout << B << endl;
  else if (B == C)
    cout << A << endl;

  return 0;
}
