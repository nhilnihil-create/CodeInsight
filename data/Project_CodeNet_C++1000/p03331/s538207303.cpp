#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main() {
  long long n;
  cin >> n;
  int minDigitSum = 100000;
  for (int i = 1; i <= (n + 1) / 2; i++) {
    int x = i;
    int digitSumX = 0;
    while (x > 0) {
      digitSumX += x % 10;
      x /= 10;
    }
    int y = n - i;
    int digitSumY = 0;
    while (y > 0) {
      digitSumY += y % 10;
      y /= 10;
    }
    if (minDigitSum > digitSumX + digitSumY)
      minDigitSum = digitSumX + digitSumY;
  }
  cout << minDigitSum << endl;
  return 0;
}