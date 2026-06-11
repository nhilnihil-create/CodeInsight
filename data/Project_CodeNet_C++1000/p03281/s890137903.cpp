#include <bits/stdc++.h>
using namespace std;

bool solve(int n) {
  int cnt = 0;
  for (int i = 1; i <= sqrt(n); i++) {
    if (n % i == 0) {
      if (i == n % i) {
        cnt++;
      } else {
        cnt += 2;
      }
    }
  }
  if (cnt == 8) {
    return true;
  } else {
    return false;
  }
}

int main() {
  int n, ans = 0;
  cin >> n;
  for (int i = 1; i <= n; i += 2) {
    if (solve(i)) ans++;
  }
  cout << ans << endl;
}
