#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x, m[1001], m2 = 0, mi, result;
  cin >> n >> x;
  for (int i = 0; i < n; i++) {
    cin >> m[i];
    m2 += m[i];
    if (i == 0) {
      mi = m[0];
    } else if (mi > m[i]) {
      mi = m[i];
    }
  }
  x -= m2;
  result = n + (x / mi);
  cout << result << endl;
}
