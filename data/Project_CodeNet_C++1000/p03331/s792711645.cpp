#include <algorithm>
#include <iostream>
#include <string>
#include <random>
#include <cassert>
#include <cstring>
#include <chrono>

using namespace std;

typedef long long ll;

int SumOfDigits(int x) {
  int result = 0;
  while (x > 0) {
    result += x % 10;
    x /= 10;
  }
  return result;
}

int main()
{
  int n;
  cin >> n;
  int result = 1 << 30;
  for (int i = 1; i < n; ++i) {
    result = min(result, SumOfDigits(i) + SumOfDigits(n - i));
  }
  cout << result << endl;
  return 0;
}
