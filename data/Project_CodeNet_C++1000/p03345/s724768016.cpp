#include <bits/stdc++.h>

#define REP(i, x) REPI(i, 0, x)
#define REPI(i, a, b) for (int i = int(a); i < int(b); ++i)
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll A, B, C, K;
  cin >> A >> B >> C >> K;
  ll a, b, c;

  // REP(i, K) {
  //   a = A;
  //   b = B;
  //   c = C;
  //   A = b + c;
  //   B = c + a;
  //   C = a + b;
  // }

  // cout << A << ":" << B << ":" << C << endl;

  // cout << A - B << endl;

  a = A;
  b = B;
  c = C;
  if (K == 0) {
    if (A - B <= 1e18) {
      cout << A - B << endl;
    } else {
      cout << "Unfair" << endl;
    }
    return 0;
  }

  if (K == 1) {
    A = b + c;
    B = c + a;
    C = a + b;

    if (A - B <= 1e18) {
      cout << A - B << endl;
    } else {
      cout << "Unfair" << endl;
    }
    return 0;
  }

  if (K % 2 == 0) {
    A = (2 * K - 2) * a + (2 * K - 2 - 1) * b + (2 * K - 2 - 1) * c;
    B = (2 * K - 2 - 1) * a + (2 * K - 2) * b + (2 * K - 2 - 1) * c;
    C = (2 * K - 2 - 1) * a + (2 * K - 2 - 1) * b + (2 * K - 2) * c;
  } else {
    --K;
    A = (2 * K - 2) * a + (2 * K - 2 - 1) * b + (2 * K - 2 - 1) * c;
    B = (2 * K - 2 - 1) * a + (2 * K - 2) * b + (2 * K - 2 - 1) * c;
    C = (2 * K - 2 - 1) * a + (2 * K - 2 - 1) * b + (2 * K - 2) * c;
    a = A;
    b = B;
    c = C;
    A = b + c;
    B = c + a;
    C = a + b;
  }

  if (A - B <= 1e18) {
    cout << A - B << endl;
  } else {
    cout << "Unfair" << endl;
  }

  return 0;
}
