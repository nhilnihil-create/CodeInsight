#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int64_t N;
  cin >> N;
  N++;
  int nod = 0;
  while (N > 10) {
    N /= 10;
    nod++;
  }
  cout << N - 1 + 9 * nod << '\n';
  return 0;
}
