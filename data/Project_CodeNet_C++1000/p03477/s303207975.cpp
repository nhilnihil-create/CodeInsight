#include <iostream>
using namespace std;

int main()
{
  int a,b,c,d,e,f;
 cin >>a;
  cin >>b;
  cin >>c;
  cin >>d;
  e=(a+b);
  f=(c+d);
  
  if (e>f)
  {
    cout << "Left"<< endl;
  }
  if (f>e)
  {
    cout << "Right"<< endl;
  }
  if (e==f)
  {
    cout << "Balanced"<< endl;
  }
  return 0;
}