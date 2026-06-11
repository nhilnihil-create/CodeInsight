#include <iostream>
using namespace std;

int findSumOfDigits(int n) {
  int sum = 0;
  while (n > 0) {
    sum += n % 10;
    n /= 10;
  }
  return sum;
}

int main() {
  int N;
  cin >> N;
  int M = 100000;
  for (int a = 1; a < N; a++) {
    int b = N - a;
    int sum = findSumOfDigits(a) + findSumOfDigits(b);
    if (sum < M) M = sum;
  }
  cout << M << endl;
}
