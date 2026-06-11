#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, A, B, C;
  cin >> N >> A >> B >> C;
  vector<int> l(N);
  for (auto &x : l) cin >> x;

  int a, b, c, mp, ans{1000000000};
  for (unsigned i = 0, n = 1 << N * 2; i != n; ++i) {
    a = b = c = 0;
    mp = -30;
    for (int j = 0; j != N; ++j) {
      switch ((i >> j * 2) & 3) {
        case 1:
          a += l[j];
          mp += 10;
          break;
        case 2:
          b += l[j];
          mp += 10;
          break;
        case 3:
          c += l[j];
          mp += 10;
          break;
      }
    }

    if (!a || !b || !c) continue;

    ans = min(ans, mp + abs(A - a) + abs(B - b) + abs(C - c));
  }

  cout << ans << endl;
}
