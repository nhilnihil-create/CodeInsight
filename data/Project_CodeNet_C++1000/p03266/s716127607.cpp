#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <numeric>
using namespace std;
int main() {
  int n, k;
  long long a = 0, b = 0;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    if (i%k == 0) {
      a++;
    }
    if (i%k == (double)k/2) {
      b++;
    }
  }
  cout << a*a*a+b*b*b << endl;
}