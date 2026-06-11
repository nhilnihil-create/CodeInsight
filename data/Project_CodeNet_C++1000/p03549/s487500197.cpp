#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;

  int round = 1900 * M + 100 * (N - M);
  cout << round * (1 << M) << endl;
  return 0;
}
