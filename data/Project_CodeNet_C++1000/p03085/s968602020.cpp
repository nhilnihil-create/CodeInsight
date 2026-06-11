#include <iostream>

using namespace std;

int main(){
  char a;
  cin >> a;
  if(a=='A') cout << 'T';
  if(a=='T') cout << 'A';
  if(a=='C') cout << 'G';
  if(a=='G') cout << 'C';
}