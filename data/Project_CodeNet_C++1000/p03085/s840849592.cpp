#include <iostream>
using namespace std;

int main(){
  char b;
  cin >> b;
  
  if(b == 'A') cout << 'T' << endl;
  if(b == 'C') cout << 'G' << endl;
  if(b == 'G') cout << 'C' << endl;
  if(b == 'T') cout << 'A' << endl;
  
  return 0;
}