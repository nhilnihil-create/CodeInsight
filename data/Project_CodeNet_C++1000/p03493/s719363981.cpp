#include <iostream>
#include <string>
using namespace std;
int main(){

  string a ;
  cin >> a ;
  int counter = 0 ;
  if(a[0] == '1') counter++;
  if(a[1] == '1') counter = counter+1;
  if(a[2] == '1') counter = counter+1;
  
  cout << counter << endl;
  
  
  
}