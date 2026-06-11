#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;

  int X = N;
  int K = 1;
  while(X >= 10) {
    X /= 10;
    K *= 10;
  }
  int sum = 0;
  X = N;
  while (K) {
    sum += X / K;
    X %= 10;
    K /= 10; 
  } 

  if(N % sum == 0) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}
