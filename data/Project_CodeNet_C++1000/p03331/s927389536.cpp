#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

int ketawa(int n) {
  int ret = 0;
  while (n >= 1) {
    ret += n % 10;
    n /= 10;
  }
  return ret;
}

int main() {
  int n;
  cin >> n;
  int ans = 1e9;
  for (int i = 1; i <= n / 2; i++) {
    ans = min(ans, ketawa(i) + ketawa(n - i));
  }
  cout << ans << endl;
  return 0;
}