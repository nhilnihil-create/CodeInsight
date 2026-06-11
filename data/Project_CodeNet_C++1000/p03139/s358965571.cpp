#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, a, b;
  cin >> n >> a >> b;
  int ans1, ans2;
  if (a >= b) {
    ans1 = b;
  } else {
    ans1 = a;
  }
  if ((a+b)-n > 0) {
    ans2 = a + b - n;
  } else {
    ans2 = 0;
  }
  cout << ans1 << ' ' << ans2 << endl;
}