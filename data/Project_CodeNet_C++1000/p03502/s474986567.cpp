#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N, x = 0;
  cin >> N;
  int M = N;
  while (M > 0) {
    x += M % 10;
    M /= 10;
  }
  //cout << x <<endl;
  if (N % x) {
    cout << "No" <<endl;
  }
  else {
    cout << "Yes" <<endl;
  }
}