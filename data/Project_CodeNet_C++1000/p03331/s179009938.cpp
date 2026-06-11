#include<bits/stdc++.h>
using namespace std;

int calcDigitSum(int n) {
  int digitSum = 0;
  string s = to_string(n);
  for (char c: s) {
    digitSum += c - '0';
  }
  return digitSum;
}

int main() {
  int N;
  cin >> N;
  
  int a, b, tmp;
  int min = 108;
  for (a = 1; a < N; a++) {
    b = N - a;
    tmp = calcDigitSum(a) + calcDigitSum(b);
    if (tmp < min) {
      min = tmp;
    }
  }
  
  cout << min << endl;
}
