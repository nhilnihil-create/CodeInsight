#include <bits/stdc++.h>
using namespace std;
// Harshad Number
int main() {
  int N, c;
  cin >> N;

  for (int n = N; n != 0; n /= 10) {
    c += n % 10;
  }
  
  if (N % c == 0) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}