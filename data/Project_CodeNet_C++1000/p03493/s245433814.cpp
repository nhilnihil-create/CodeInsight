#include <bits/stdc++.h>
using namespace std;

int main() {
  string A;
  cin >> A;
  int B=0;
  
  for (int i=0;i<3;i++){
    if(A.at(i)=='1'){
      B++;
    }  
  }  
  cout << B << endl;
}