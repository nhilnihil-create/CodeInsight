#include <bits/stdc++.h>

using namespace std;

const int N = (int) 4e6 + 46;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  bitset<N> occ;
  occ[0] = 1;
  long long sm = 0;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    sm += x;
    occ |= (occ << x);
  }
  for (int i = 0; i < N; i++) {
    if (occ[i] && 2 * i >= sm) {
      cout << i << '\n';
      return 0;
    }
  }
  return 0;
}
