#include <iostream>
using namespace std;

int main ()
{
  int a, b, c;
  cin >> a >> b >> c;
  
  if(a == b && a == c)
  {
    if(a >= 0)
    {
	  cout << "Yes" << endl;
    }
    else
    {
      cout << "No" << endl;
    }
  }
  else
  {
    cout << "No" << endl;
  }
}
