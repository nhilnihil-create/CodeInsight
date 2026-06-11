#include <bits/stdc++.h>

#define REP(i, x) REPI(i, 0, x)
#define REPI(i, a, b) for (int i = int(a); i < int(b); ++i)
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int A, B;
  cin >> A >> B;
  if (A > 8 || B > 8) {
    cout << ":(" << endl;
  } else {
    cout << "Yay!" << endl;
  }

  return 0;
}
