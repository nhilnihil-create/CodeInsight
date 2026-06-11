#include<iostream>
using namespace std;

int main(){
  int k, a, b;
  cin >> k;
  if(k % 2 == 0){
  a = k / 2;
  b = k / 2;
    cout << a * b;
  }
  else {
    a = k / 2 + 1;
    b = k / 2;
    cout << a * b;
  }
}
  