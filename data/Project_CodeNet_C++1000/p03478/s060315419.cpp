#include <iostream>
using namespace std;
int main() {
  int n, a, b, sum = 0;
  cin >> n >> a >> b;
  for (int i = 1; i <= n; i++) {
    int d5 = i / 10000;
    int n4 = i % 10000;
    int d4 = n4 / 1000;
    int n3 = n4 % 1000;
    int d3 = n3 / 100;
    int n2 = n3 % 100;
    int d2 = n2 / 10;
    int d1 = n2 % 10;
    int dsum = d5 + d4 + d3 + d2 + d1;
    if (dsum >= a && dsum <= b) {
      sum += i;
    }
  }
  cout << sum << endl;
  return 0;
}