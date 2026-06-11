#include <bits/stdc++.h>
using namespace std;

int sod(long a) {
  int b = 0;
  while (a > 0) b += a % 10, a /= 10;
  return b;
}

int main() {
  int N, A, B;
  cin >> N >> A >> B;
  int ans = 0;
  for (int i = 1; i <= N; i++) {
    if (sod(i) >= A && sod(i) <= B) ans += i;
  }
  cout << ans << "\n";
}