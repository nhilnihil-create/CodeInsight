#include <bits/stdc++.h>

using namespace std;

int sum_elements(int n) {
  int sum = 0, m;

  while(n > 0) {    
    m = n % 10;    
    sum = sum + m;    
    n = n / 10;    
  }
  return sum;
}

int main () {
  
  int N, ans = INT_MAX;

  cin >> N;

  int A = 1, B = N - 1, t;

  while (A <= (N / 2)) {
    t = sum_elements(A) + sum_elements(B);
    if (t < ans) {
      ans = t;
    }
    A++;
    B--;
  }

  cout << ans << endl;

  return 0;
}