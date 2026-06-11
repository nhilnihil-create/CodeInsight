#include <iostream>

using namespace std;

int main() {
  long long N;
  cin >> N;
  long long tmp = N/4;
  for (long long h = tmp > 1 ? tmp : 1; (4*h <= 3*N) && (h <= 3500) ; h++) {
    for (long long n = h; n <= 3500; n++) {
      long long hn = h*n;
      long long h_n = h+n;
      for (long long w = 3*tmp > n ? 3*tmp : n; w <= 3500; w++) {
        if (4*hn*w == N*(hn+w*h_n)) {
          cout << h << ' ' << n << ' ' << w << endl;
          return 0;
        }
      }
    }
  }
}