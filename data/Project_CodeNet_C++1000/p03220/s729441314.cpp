#include <cmath>
#include <iostream>
#define rep(S, L) for (int i = S; i < L; ++i)
using namespace std;

int main() {
  int n, t, a, h;
  cin >> n >> t >> a;
  double diff = 10000.0;
  int idx = -1;
  for (int i = 0; i < n; ++i) {
    cin >> h;
    double x = t - h * 0.006;
    double b = abs(a - x);
    if (b < diff) {
      idx = i + 1;
      diff = b;
    }
  }
  cout << idx << endl;
  return 0;
}
