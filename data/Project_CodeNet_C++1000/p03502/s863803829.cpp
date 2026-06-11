#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  ll n;
  cin >> n;
  int x = 0, nn = n;
  while (nn > 0) {
    x += nn % 10;
    nn /= 10;
  }
  cout << (n % x == 0 ? "Yes" : "No") << endl;
  return 0;
}
