#include <bits/stdc++.h>
#define rep(i, f, n) for (int i = (f); i < (int)(n); i++)
#define repe(i, f, n) for (int i = (f); i <= (int)(n); i++)
using namespace std;
using ll = long long;

bool even(int n) { return n % 2 == 0; }

int main() {
  int A, B, C;
  cin >> A >> B >> C;

  int m = max(max(A, B), C);
  int m3 = m * 3;
  int tot = A + B + C;

  int ans = 0;
  if (even(m3) && even(tot) || !even(m3) && !even(tot)) {
    ans = (m3 - tot) / 2;
  } else {
    ans = ((m + 1) * 3 - tot) / 2;
  }

  cout << ans << endl;

  return 0;
}
