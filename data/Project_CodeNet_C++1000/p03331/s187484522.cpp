
#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  int sum = 0;
  int minv = INT_MAX;
  for (int i = 1; i < n; ++i) {
    sum = 0;
    sum += i % 10 + (n - i) % 10;
    sum += i / 10 % 10 + (n - i) / 10 % 10;
    sum += i / 100 % 10 + (n - i) / 100 % 10;
    sum += i / 1000 % 10 + (n - i) / 1000 % 10;
    sum += i / 10000 % 10 + (n - i) / 10000 % 10;
    if (i == 0)
      minv = sum;
    else
      minv = min(minv, sum);
  }

  cout << minv << endl;
}