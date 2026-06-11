#include <bits/stdc++.h>
using namespace std;

int digits(int n) {
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
  int d = N;
  
  for (int i = 1; i < N; i++) {
    int a = digits(i);
    int b = digits(N - i);
    d = min(d, a + b);
  }
  cout << d << endl;
}
