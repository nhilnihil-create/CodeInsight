#include <cmath>
#include <iostream>
#define rep(S, L) for (int i = S; i < L; ++i)
using namespace std;

int main() {
  int d, n;
  cin >> d >> n;
  int ans = 0;
  if (d == 0) {
    int loop = 0;
    int count = 0;
    while (count < n) {
      loop += 1;
      if (loop % 100 == 0) {

      } else {
        count += 1;
      }
    }
    ans = loop;
  } else if (d == 1) {
    int loop = 0;
    int count = 0;
    while (count < n) {
      loop += 1;
      if (loop % 100 == 0 && loop % 10000 > 0) {
        count += 1;
      }
    }
    ans = loop;
  } else if (d == 2) {
    int loop = 0;
    int count = 0;
    while (count < n) {
      loop += 1;
      if (loop % 10000 == 0 && loop % 1000000 > 0) {
        count += 1;
      }
    }
    ans = loop;
  }
  cout << ans << endl;
  return 0;
}
