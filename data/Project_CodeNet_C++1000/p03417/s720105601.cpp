#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n, m;
  cin >> n >> m;
  if (n > m) swap(n, m);
  if (m == 1) {
    cout << 1 << endl;
    return 0;
  }
  if (n == 1) {
    cout << m - 2 << endl;
    return 0;
  }
  ll ret = (ll)(n - 2) * (m - 2);

  cout << ret << endl;
}
