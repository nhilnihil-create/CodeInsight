#include<iostream>
using namespace std;

int main(){
  int A, B;
  cin >> A >> B;
  if(A == B){
    cout << A+B << endl;
  }else{
    cout << (A > B ? A+A-1 : B+B-1) << endl;
  }
  
  return 0;
}