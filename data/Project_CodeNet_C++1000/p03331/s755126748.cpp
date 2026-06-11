#include <bits/stdc++.h>
using namespace std;
int sum (int n){
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
  int minimum = 100000;
  for (int A = 1; A < N; A++) {
    if (sum(A) + sum(N - A) < minimum) {
      minimum = sum(A) + sum(N - A);
    }
  }
  cout << minimum << endl;
  return 0;
}
