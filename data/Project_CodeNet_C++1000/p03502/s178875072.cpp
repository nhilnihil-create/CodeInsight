#include <bits/stdc++.h>
using namespace std;

int get_sum_of_each_digit(int num) {
  int sum = 0;
  while (num > 0) {
    sum += num % 10;
    num /= 10;
  }
  return sum;
}

int main() {
  int N;
  cin >> N;

  if (N % get_sum_of_each_digit(N) == 0) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}