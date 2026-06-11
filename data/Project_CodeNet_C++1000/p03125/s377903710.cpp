#include <bits/stdc++.h>
using namespace std;

int main(void){
  int A, B;
  cin >> A >> B;
  if(B % A == 0) cout << A + B;
  else cout << B - A;
  return 0;
}