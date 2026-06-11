#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,A,B;
  1 <= N <= 20;
  1 <= A <= 100;
  1 <= B <= 2000;
  cin >> N >> A >> B;
  if (A*N <= B) {
    cout << A*N << endl;
  } else {
    cout << B << endl;
  }
}
