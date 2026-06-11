#define _GIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;


int main(void) {
  int n, y;
  cin >> n >> y;

  for (int i = 0; i <= n; ++i) {
    for (int j = 0; i + j <= n; ++j) {
      int num = i * 10000 + j * 5000;
      int num2 = n - (i + j);
      if ((y - num) / 1000 == num2) {
        cout << i << ' ' << j << ' ' << num2 << endl;
        return 0;
      }
    }
  }

  cout << -1 << ' ' << -1 << ' ' << -1 << endl;
  
  return 0;
}