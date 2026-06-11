#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

ll a, b, c, k;

int main() {
  cin >> a >> b >> c >> k;
  cout << (k % 2 == 0 ? a - b : b - a) << endl;
  return 0;
}
