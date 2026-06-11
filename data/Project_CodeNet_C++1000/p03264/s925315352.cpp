#include <bits/stdc++.h>

#define REP(i, x) REPI(i, 0, x)
#define REPI(i, a, b) for (int i = int(a); i < int(b); ++i)
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int K;
  cin >> K;
  if (K % 2 == 0) {
    cout << K * K / 4 << endl;
  } else {
    cout << ((K - 1) / 2) * (K / 2 + 1) << endl;
  }
  return 0;
}
