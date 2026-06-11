#include <bits/stdc++.h>
using namespace std;

int findSumDigit(int n) {
  int sum = 0;
  while (n > 0) {
    sum += n % 10;
    n /= 10;
  }
  return sum;
}

int main() {
  int n, total;
  cin >> n;
  total = findSumDigit(n);
  if (n % total == 0) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}
