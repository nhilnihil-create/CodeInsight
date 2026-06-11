#include<iostream>
 
using namespace std;
 
int main(){
  int a, b;
  cin >> a >> b;
  int n = a + b;
  
  if (n % 2 == 1) {
    cout << n / 2 + 1;
  }
  else {
    cout << n / 2;
  }
}