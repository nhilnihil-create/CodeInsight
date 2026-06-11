#include <bits/stdc++.h>
using namespace std;

int main(){
  int T, A, B;
  
  cin >> T >> A >> B;
  
  if(A*T<B)
    cout << A*T << endl;
  else
    cout << B << endl;
}