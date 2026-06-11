#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int A,B,C,D;
  cin >> A>> B;
  C = A + B;
  D = B - A;
  if(B % A == 0)
    cout << C;
  else
    cout << D;
}