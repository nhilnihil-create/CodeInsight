#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, A, B;
  cin >> N >> A >>B;
  int a, b;
  a = A * N ;
  b = B ;

  if (a <= b) {
    cout << a << endl;
  }
  else {
    cout << b << endl;
  }
}