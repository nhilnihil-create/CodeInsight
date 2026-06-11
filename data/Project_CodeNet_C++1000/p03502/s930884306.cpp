#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N,n;
  int sum = 0;
  
  cin >> N;
  n = N;
  
  for (int i = 0; i < N; i++) {
    sum += N % 10;
    N /= 10;
    
    if (N % 10 == N) {
      sum += N;
      break;
    }
  }

  if (n % sum == 0) {
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }
}