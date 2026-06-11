#include <iostream>
using namespace std;

int main()
{
  int a,b,c,d,e,f;
  cin >> a;
  cin >> b;
  c=(a+b);
  d=((c+1)/2);
  e=(c%2);
  f=(c/2);
  if (e==0)
  {
    cout << f<< endl;
  }
  else 
  {
    cout << d<< endl;
  }
  return 0;
 }