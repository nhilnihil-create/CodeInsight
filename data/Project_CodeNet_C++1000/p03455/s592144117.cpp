#include <iostream>
 
using namespace std;
 
int main()
{
  int x,y;
  
  cin >> x >> y;
  
  if ( (x*y)%2 ) cout << "Odd\n";
  else cout << "Even\n";
  
}