#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, foo, ans = 0;
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> foo;
    if ((foo & 1) == 0) {
      foo >>= 1;
      ans++;
      while ((foo & 1) == 0) {
        foo >>= 1;
        ans++;
      }
    }
  }
  cout << ans;
  return 0;
}