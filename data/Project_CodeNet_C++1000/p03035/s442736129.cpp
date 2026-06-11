#include<bits/stdc++.h>
using namespace std;

int main(){
  
  int A, B;
  cin >> A >> B;
  
  if(A > 12){
    cout << B << endl;
    return 0;
  }
  if(A > 5){
    cout << B/2 << endl;
    return 0;
  }
  cout << 0 << endl;
  return 0;
}