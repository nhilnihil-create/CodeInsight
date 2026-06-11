#include <bits/stdc++.h>

using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  int nsubmit = 1;
  for (int i = 0; i < M; i++) {
    nsubmit *= 2;
  }
  int ans = (1900 * M + 100 * (N - M)) * nsubmit;
  cout << ans << endl;

  return 0;
}
/* vim:set fdm=marker: */
