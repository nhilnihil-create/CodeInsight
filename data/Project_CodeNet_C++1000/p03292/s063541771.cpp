#include <algorithm>
#include <iostream>
#define rep(S, L) for (int i = S; i < L; ++i)
using namespace std;

int main() {
  int a[3];
  rep(0, 3) { cin >> a[i]; }
  sort(a, a + 3, greater<int>());
  int ans = abs(a[1] - a[0]) + abs(a[2] - a[1]);
  cout << ans << endl;
  return 0;
}
