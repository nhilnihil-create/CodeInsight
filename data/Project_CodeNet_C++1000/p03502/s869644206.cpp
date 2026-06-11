#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;

  int n = N;
  int fsum = 0;
  
  while (n) {
    fsum += (n % 10);
    n /= 10;
  }
  
  if ((N % fsum) == 0) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}
