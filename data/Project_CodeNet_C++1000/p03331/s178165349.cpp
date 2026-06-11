#include <bits/stdc++.h>
using namespace std;

int number(int n) {
  int sum = 0;
  while (n > 0) {
    sum += n%10;
    n /= 10;
  }
  return sum;
}

int main() {
  int n;
  cin >> n;
  
  int total = 1000000;
  for (int a = 1; a < n; a++) {
    int b = n - a;
    int sum = number(a) + number(b);
    if (sum < total) total = sum;
  }
  cout << total << endl;
}

