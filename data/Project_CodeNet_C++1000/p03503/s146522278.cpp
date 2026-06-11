#include <algorithm>
#include <iostream>

using namespace std;

int main() {
  int N, F[100][10], P[100][11], ans{-1000000000}, g, a;
  cin >> N;
  for (int i = 0; i != N; ++i)
    for (int &f : F[i]) cin >> f;
  for (int i = 0; i != N; ++i)
    for (int &p : P[i]) cin >> p;
  for (int i = 1, n = 1 << 10; i != n; ++i) {
    g = 0;
    for (int j = 0; j != N; ++j) {
      a = 0;
      for (int t = 0; t != 10; ++t)
        if (i & (1 << t) && F[j][t]) ++a;
      g += P[j][a];
    }
    ans = max(ans, g);
  }

  cout << ans << endl;
}
