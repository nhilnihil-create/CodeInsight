#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  int ans = 0;
  while (N > 0) {
    ans += N % 10;
    N /= 10;
  }
  if (ans > 1) cout << ans << endl;
  else cout << 10 << endl;
}

