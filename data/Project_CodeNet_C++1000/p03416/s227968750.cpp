#include <bits/stdc++.h>
using namespace std;
int main() {
  int A, B;
  int x = 0;
  cin >> A >> B;
  for (int i = 0; A <= B; i++) {
    if (A % 10 == A / 10000  &&  A % 100 / 10 == A % 10000/ 1000) {x++;}
    A++;}
  cout << x << endl;
}