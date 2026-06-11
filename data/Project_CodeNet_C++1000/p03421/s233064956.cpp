#include <bits/stdc++.h>
using namespace std;

int main() {
  long long n, a, b;
  cin >> n >> a >> b;
  if (n < a + b - 1 || n > a * b) {
    cout << -1 << endl;
    return 0;
  }
  long long idx = 1;
  long long remainder = n - a;
  while (idx <= n) {
    long long offset = min(b - 1, remainder);
    for (int i = offset; i >= 0; i--) {
      cout << idx + i << " ";
    }
    idx += offset + 1;
    remainder -= offset;
  }
  cout << endl;
  return 0;
}