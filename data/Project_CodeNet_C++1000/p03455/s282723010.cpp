#include <bits/stdc++.h>
using namespace std;

int main () {
  int A, B;
  cin >> A >> B;
  int C = A * B % 2;
  if (C == 1) {
    cout << "Odd" <<endl;
  }
  else {
    cout << "Even" << endl;
  }
  
  
}