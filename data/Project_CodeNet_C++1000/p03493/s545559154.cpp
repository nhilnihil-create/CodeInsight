#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int A, num, a1, a2;
  cin >> A;
  a1 = A%10;
  a2 = ((A-a1)%100)/10;
  num = a1 + a2 + (A - 10*a2 -a1)/100;
  cout << num <<endl;
}