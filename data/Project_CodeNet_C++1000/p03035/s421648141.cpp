#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int a, b;
  cin >> a >> b;
  int ans;
  if (a >= 13) {
    ans = b;
  } else if (a >= 6) {
    ans = b / 2;
  } else {
    ans = 0;
  }

  cout << ans << endl;

  return 0;
}
