#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, a = 0, n;
  cin >> N;
  n = N;
  
  for (int i = 0; i < 9; i++) {
	a += N % 10;
    N /= 10;
  }
  
  if (n % a == 0) {
  	cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}
