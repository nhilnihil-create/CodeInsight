#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, A, B, C;
  cin >> N >> A >> B >> C;
  vector L(N, 0);
  for (int &l : L) cin >> l;

  int ans = INT_MAX;
  for (int bit = 0; bit < pow(4, N); bit++) {
    int cost = 0, a = 0, b = 0, c = 0;
    for (int i = 0, dig = 1; i < N; i++, dig *= 4) {
      int tmp = bit / dig % 4;
      if (tmp == 1) cost += (a) ? 10 : 0, a += L.at(i);
      if (tmp == 2) cost += (b) ? 10 : 0, b += L.at(i);
      if (tmp == 3) cost += (c) ? 10 : 0, c += L.at(i);
    }
    if (!a || !b || !c) continue;
    cost += abs(A - a) + abs(B - b) + abs(C - c);
    ans = min(ans, cost);
  }
  cout << ans << "\n";
}