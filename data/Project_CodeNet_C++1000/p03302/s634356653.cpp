#include <iostream>
using namespace std;

int main(){
  int a, b;
  cin >> a >> b;
  
  char result;
  if(a + b == 15) result = '+';
  else if(a * b == 15) result = '*';
  else result = 'x';
  
  cout << result;
}