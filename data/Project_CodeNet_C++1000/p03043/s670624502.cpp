#include <cmath>
#include <cstdint>
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
  int64_t N, K;
  cin >> N >> K;
  
  long double per = 0.0;
  for (int64_t n = 1; n <= N; ++n) {
    long double tmp = 1.0 / N;
    int64_t now = n;
    while (now < K) {
      now *= 2;
      tmp /= 2.0;
    }
    per += tmp;
  }
  cout << fixed << setprecision(12);
  cout << per << endl;
  
  return 0;
}
