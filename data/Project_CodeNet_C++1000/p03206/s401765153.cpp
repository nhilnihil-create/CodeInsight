#include <bits/stdc++.h>

#define REP(i, x) REPI(i, 0, x)
#define REPI(i, a, b) for (int i = int(a); i < int(b); ++i)
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int D;
  cin >> D;
  switch (D) {
  case 22:
    cout << "Christmas Eve Eve Eve" << endl;
    break;
  case 23:
    cout << "Christmas Eve Eve" << endl;
    break;
  case 24:
    cout << "Christmas Eve" << endl;
    break;
  case 25:
    cout << "Christmas" << endl;
    break;
  default:
    return -1;
  }

  return 0;
}
