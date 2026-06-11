#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int A,B,C,D,E;
  cin >> A;
  B=A/1000;//1000
  C=A%1000/100;//100
  D=(A%1000)%100/10;//10
  E=((A%1000)%100)%10;//1
  
   if (B!=C && D!=E) {
    cout << "No" << endl;
  }
  else if (C!=D){
    cout << "No" << endl;
  }
  else {
  	cout << "Yes" << endl;
  }
}