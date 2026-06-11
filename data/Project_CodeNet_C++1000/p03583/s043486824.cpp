#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX = 3500;
 
int main() {
  long long n;
  cin >> n;
  for (long long a = 1; a <= MAX; a++) {
    for (long long b = 1; b <= MAX; b++) {
      long long x = n * a * b;
      long long y = 4 * a * b - n * b - n * a;
      if (y > 0 && x % y == 0) {
        long long c = x / y;
        cout << a << " " << b << " " << c << endl;
        return 0;
      }
    }
  }
  return 0;
}