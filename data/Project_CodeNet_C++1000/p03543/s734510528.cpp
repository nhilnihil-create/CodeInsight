#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, n;
  cin >> N;

  n = N % 1000;

  if (N % 1110 <= 9) {
    cout << "Yes" << endl;
  }
  else if (n % 111 == 0 || n == 0) {
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }
}