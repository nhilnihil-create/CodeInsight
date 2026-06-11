#include<bits/stdc++.h>
using namespace std;

int calcDigitSum(int n) {
  int digitSum = 0;
  for (int j = n; j > 0; j /= 10) {
    digitSum += j % 10;
  }
  return digitSum;
}

int main() {
  int N;
  cin >> N;
  
  int a, b, tmp, upper = N / 2 + 1;
  int min = 108;
  for (a = 1; a <= upper; a++) {
    b = N - a;
    tmp = calcDigitSum(a) + calcDigitSum(b);
    if (tmp < min) {
      min = tmp;
    }
  }
  
  cout << min << endl;
}
