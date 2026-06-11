#include <bits/stdc++.h>
using namespace std;
int main() {
  int N, A, B;
  cin >> N >> A >> B;
  int x, y, z;
  x = y = z = 0;
  for (int i = 0; i < N; i++) {
    int p;
    cin >> p;
    if (p <= A) {
        x++;
    } else if (p <= B) {
        y++;
    } else {
        z++;
    }
  }
  int ans;
  ans = min(x, min(y, z));
  cout << ans << '\n';
  return 0;
}