#include <bits/stdc++.h>
using namespace std;

int main() {
  double a, b;
  cin >> a >> b;
  double A = (a+b)/2;
  int B = (a+b)/2;
  if ((A-B) != 0){
    B++;
  }
  cout << B <<endl;
}