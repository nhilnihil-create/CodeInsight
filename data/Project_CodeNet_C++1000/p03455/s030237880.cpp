#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b;
  cin >> a >> b;
  int c = a * b;

  if ( c % 2 == 0) {
    puts ("Even");
  }
  else puts ("Odd");
  return 0;
}