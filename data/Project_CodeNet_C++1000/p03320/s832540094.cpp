#include <bits/stdc++.h>
using namespace std;

int main() {
  double min = 999999999999999.0;
  vector<long long> answers;
  for (long long i = 1000000000000LL; i > 0; i /= 10) {
    for (int j = 1000; j > 100; j--) {
      long long n = i * j - 1;
      long long x = n;
      int s = 0;
      while (x > 0) {
        s += x % 10;
        x /= 10;
      }
      double v = (double) n / s;
      if (v <= min) {
        min = v;
        answers.push_back(n);
      }
    }
  }
  for (long long i = 100; i > 0; i--) {
    long long x = i;
    int s = 0;
    while (x > 0) {
      s += x % 10;
      x /= 10;
    }
    double v = (double) i / s;
    if (v <= min) {
      min = v;
      answers.push_back(i);
    }
  }
  reverse(answers.begin(), answers.end());
  int k;
  cin >> k;
  for (int ki = 0; ki < k; ki++) {
    cout << answers[ki] << endl;
  }
  return 0;
}