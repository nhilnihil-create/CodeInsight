#include <iostream>
#include <set>
using namespace std;

using int64 = long long;
const int64 kMax = 1e+17;
using Data = pair<double, int64>;

double ndivs(int64 n) {
  double s = 0;
  for (int64 k = n; k; k /= 10)
    s += k % 10;
  return n / s;
}

int main() {
  int64 k;
  cin >> k;

  set<Data> data;
  for (int64 base = 1; base < kMax; base *= 10) {
    for (int64 d = 1; d < 1000 && d < (kMax / base); ++d) {
      int64 n = (d + 1) * base - 1;
      data.insert(Data(ndivs(n), n));
    }
  }

  int64 v = 0;
  for (auto itr = data.begin(); k; ++itr) {
    int64 n = itr->second;
    if (v < n) {
      v = n;
      cout << n << "\n";
      --k;
    }
  }

  return 0;
}
