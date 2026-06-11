#include <bits/stdc++.h>
using namespace std;

int main(){
  int T,A,B,P1;
  cin >> T >> A >> B;
  P1 = T*A;
  if (P1<=B){
    cout << P1 << endl;
  }
  else{
    cout << B << endl;
  }
}