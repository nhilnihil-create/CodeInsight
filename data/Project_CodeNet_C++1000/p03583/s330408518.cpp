#include <iostream>

using namespace std;

int main() {
  long long N;
  cin >> N;
  long long tmp = N/4;
  for (long long h = tmp > 1 ? tmp : 1; (4*h <= 3*N) && (h <= 3500) ; h++) {
    for (long long w = 3*tmp > h ? 3*tmp : h; w <= 3500; w++) {
      if (4*h*w-N*(h+w) == 0) continue;
      long long n = N*h*w/(4*h*w-N*(h+w));
      if (n <= 0) continue;
      if (4*h*n*w == N*(h*n+n*w+w*h)) {
        cout << h << ' ' << n << ' ' << w << endl;
        return 0;
      }
    }
  }
}