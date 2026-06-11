#include <bits/stdc++.h>
using namespace std;

int main() {
  long N;
  cin >> N;
  long ans = 2e18;
  for (int i = 1; i <= N - 1; i++) {
    int A = i;
    int B = N - i;
    int a = 0;
    while (A) a += A % 10, A /= 10;
    int b = 0;
    while (B) b += B % 10, B /= 10;
    ans = min(ans, (long)a + b);
  }
  cout << ans << "\n";
}