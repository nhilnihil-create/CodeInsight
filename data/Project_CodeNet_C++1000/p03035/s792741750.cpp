#include<bits/stdc++.h>
using namespace std;

int main(void){
  int A, B;
  cin >> A >> B;
  if(A >= 13)
    cout << B << "\n";
  else if(A >= 6)
    cout << B / 2 << "\n";
  else
    cout << 0 << "\n";
  return 0;
}
