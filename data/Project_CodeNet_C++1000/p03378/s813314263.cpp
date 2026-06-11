#include <algorithm>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;
using P = pair<int, int>;

int main() {
  int n, m, x;
  cin >> n >> m >> x;
  vector<int> a(n);
  rep(i, m) cin >> a[i];

  int low = 0;
  int up = 0;

  rep(i, m) {
    if (a[i] > x) {
      low++;
    } else {
      up++;
    }
  }

  cout << (low >= up ? up : low);
  return 0;
}
