#define _GIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;


int main(void) {
  ll n, m;
  cin >> n >> m;
  if (n == 1 && m == 1) {
    cout << 1 << endl;
    return 0;
  }
  if (n <= 2 && m <= 2) {
    cout << 0 << endl;
    return 0;
  }

  if (n == 1 || m == 1) {
    if (n > m) swap(n, m);
    cout << m - 2 << endl;
    return 0;
  }

  cout << (n - 2) * (m - 2) << endl;
  
  return 0;
}