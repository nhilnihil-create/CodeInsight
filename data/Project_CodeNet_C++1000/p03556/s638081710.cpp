#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  int ans = 0;
  for (int i = 1; i * i <= n; i++) {
    ans = max(ans, i * i);
  }

  cout << ans << endl;
}