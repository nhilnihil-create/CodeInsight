#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n, k;
  cin >> n >> k;

  double ans;
  rep(i, n) {
    int j = 1, l = n - i;
    while (l * j < k) j <<= 1;
    ans += 1.0 / j;
  }
  ans /= n;

  cout << setprecision(12);
  cout << ans << endl;
}