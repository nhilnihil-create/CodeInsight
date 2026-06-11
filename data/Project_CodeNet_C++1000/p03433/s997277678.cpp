#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, A, B;
  cin >> N >> A;
  
  if (N >= 1 && N <= 10000 && A >= 0 && A <= 1000 && N >= 500) {
    B = N / 500;
    B = N - B * 500;
    if (A >= B) {
      cout << "Yes" << endl;
    }
    else {
      cout << "No" << endl;
    }
  }
  else if (N < A) { 
    cout << "Yes" << endl;
  }
}