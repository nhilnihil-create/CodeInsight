#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;

  int ans = 1;
  for (int i = 0; i < n; i++) {
    if (2*ans >= ans+k) ans = ans+k;
    else ans = 2*ans;
  }

  cout << ans << endl;

}
