#include<iostream>
using namespace std;

int main(){
  int a, b, c;
  cin >> a >> b >> c;
  
  int M = max(max(a, b), c);
  if(M == a){
    cout << a*10 + b + c << endl;
  }else if(M == b){
    cout << M*10 + a + c << endl;
  }else{
    cout << M*10 + a + b << endl;
  }
  return 0;
}