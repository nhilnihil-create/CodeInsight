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
  char A, B;
  cin >> A >> B;
  if (A == B) {
    cout << "=" << endl;
  } else if (A < B) {
    cout << "<" << endl;
  } else {
    cout << ">" << endl;
  }

  return 0;
}
