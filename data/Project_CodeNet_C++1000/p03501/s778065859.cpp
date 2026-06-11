#include <bits/stdc++.h>
using namespace std;

int main() {
  int T;
  int A;
  int B;
  
  cin >> T >> A >> B;
  
  if((T * A) >= B){
  	cout << B << endl;
  }else if((T * A) < B){
  	cout << T * A << endl;
  }
}