#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  
  int mindata = 1000000;
  for (int i = 1; i <= (N + 1) / 2; ++i) {
    int a = i;
    int b = N - i;
    
    int sum_a, sum_b;
    sum_a = sum_b = 0;
    
    while (a > 0) {
      sum_a += (a % 10);
      a /= 10;
    }
    while (b > 0) {
      sum_b += (b % 10);
      b /= 10;
    }
    int sum = sum_a + sum_b;
    
    mindata = min(mindata, sum);
    
  }
  cout << mindata << endl;
}