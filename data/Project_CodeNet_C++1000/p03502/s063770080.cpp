#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, Har = 0;
  cin >> N;
  
  int M = N;
  
  for (int i = 0; i < 9; i++) {
    Har += N % 10;
    N /= 10;
  }
  if (M % Har == 0) {
    cout << "Yes" << endl;
  }
  else 
    cout << "No" << endl;
}