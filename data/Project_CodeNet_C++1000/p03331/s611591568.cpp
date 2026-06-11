#include <iostream>
using namespace std;

int sumOfDigit (int i) {
  return i / 10000 + i / 1000 % 10 + i / 100 % 10 + i % 100 / 10 + i % 10;
}

int main () {
  int N;
  cin >> N;
  int min = 1 << 30;
  for (int i=1; i <= (N / 2) + 1; ++i) {
    int a = i;
    int b = N - i;
    int sum_a = sumOfDigit(a);
    int sum_b = sumOfDigit(b);
    if (sum_a + sum_b < min) {
      min = sum_a + sum_b;
    }
  }
  cout << min << endl;
  return 0;
}