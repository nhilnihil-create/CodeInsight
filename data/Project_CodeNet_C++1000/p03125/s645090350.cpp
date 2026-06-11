#include <bits/stdc++.h>
using namespace std;

int main() {
  int A,B;
  cin >> A >> B;
  bool J=false;
  for(int i=0;i<B/A;i++){
    if(A*(i+1)==B){
      J=true;
    }
  }
  if(J==true){
    cout << A+B << endl;
  }else{
    cout << B-A << endl;
  }
}