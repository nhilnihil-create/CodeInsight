#include <bits/stdc++.h>
using namespace std;

int main() {
  int A;
  cin >> A;
  
  if (A < 1000) {
    cout << "ABC" << endl;
  } else if (A >= 1000 && A <= 1998) {
    cout << "ABD" << endl;
  }
}