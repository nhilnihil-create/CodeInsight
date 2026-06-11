#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int a,b,A,B;
  cin >> a >> b;
  A = a % 2;
  B = b % 2;
  if (A == 0 || B ==0) {
    cout << "Even" << endl;
  }
  else {
    cout << "Odd" << endl;
  }
}