#include <iostream>
using namespace std;

int main() 
{
  int a,b;
  cin >> a >> b;
  int pro=a*b;

  string judge;
  if( pro%2 == 0 ) 
    judge="Even";
  else
    judge="Odd";

  cout << judge << endl;
  return 0;
}