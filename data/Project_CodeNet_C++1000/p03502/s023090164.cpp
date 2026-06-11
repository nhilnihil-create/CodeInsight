#include <bits/stdc++.h>

using namespace std;

int N;

int digit_sum(int N) {
  int sum;

  for (;N != 0; N /= 10) {
    sum += N % 10;
  }

  return sum;
}

int main() {
  cin >> N;

  if (N % digit_sum(N) == 0) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

  return 0;
}