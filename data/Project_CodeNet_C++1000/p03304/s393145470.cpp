#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int m;
  long double n,d;
  cin >> n >> m >> d;

  long double res = 0;
  for (int i = 0; i < m - 1; i++) {
    if(d == 0) {
      res += (1/n);
    } else {
      res += (2*(n - d)/n/n);
    }
  }
  cout << fixed << setprecision(10) << res << '\n';
}