#include <bits/stdc++.h>

using namespace std;

int main () {
  int N, ans;

  cin >> N;

  for (int i = N; i <= INT_MAX; i = i * 2) {
    if (i % 2 == 0 && i % N == 0) {
      ans = i;
      break;
    }
  }

  cout << ans << endl;

  return 0;
}