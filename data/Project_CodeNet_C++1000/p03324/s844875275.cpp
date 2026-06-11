#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long LL;

int main() {
  int D, N; cin >> D >> N;
  int base = 1;
  for (int i = 0; i < D; ++i) base *= 100;

  int cnt = 0;
  for (int i = 0;; ++i) {
    if (i % base == 0 && i % (base * 100) != 0) ++cnt;
    if (cnt == N) {
      cout << i << endl;
      break;
    }
  }
}
