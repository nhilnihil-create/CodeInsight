#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int T,A,B,x;
  cin >> T >> A >> B;
  if(A * T >= B){
    x = B;
    cout << x << endl;
  }else if(A * T < B){
    x = A * T;
    cout << x << endl;}
}