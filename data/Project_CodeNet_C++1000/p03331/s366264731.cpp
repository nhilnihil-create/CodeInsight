#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;

int main() {
  int n;
  cin >> n;

  int min_num = 1 << 20;
  for (int i = 1; i < n; i++) {
    int a = i;
    int b = n - a;
    int sum_a = 0;
    while (a > 0) {
      sum_a += a % 10;
      a /= 10;
    }
    int sum_b = 0;
    while (b > 0) {
      sum_b += b % 10;
      b /= 10;
    }
    min_num = min(min_num, sum_a + sum_b);
  }

  cout << min_num << endl;
  return 0;
}