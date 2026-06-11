#include <bits/stdc++.h>

#define REP(i, x) REPI(i, 0, x)
#define REPI(i, a, b) for (int i = int(a); i < int(b); ++i)
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N;
  cin >> N;
  int all = 1;
  int ng = 1;
  int a;
  REP(i, N) {
    cin >> a;
    all *= 3;
    if (a % 2 == 0) {
      ng *= 2;
    } else {
      ng *= 1;
    }
  }
  cout << all - ng << endl;

  return 0;
}
