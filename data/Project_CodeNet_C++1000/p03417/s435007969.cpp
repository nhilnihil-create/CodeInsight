#include <bits/stdc++.h>

using namespace std;

int main() {
  long long N, M;
  cin >> N >> M;
  if (N > M) swap(N, M);
  long long ans;
  if (N == 1) {
    if (M == 1) {
      ans = 1;
    } else {
      ans = M - 2;
    }
  } else {
    ans = (N - 2) * (M - 2);
  }
  cout << ans << endl;

  return 0;
}
/* vim:set fdm=marker: */
