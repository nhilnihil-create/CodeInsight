#include <iostream>

using namespace std;

int main()
{
  int a,b,k;
  cin >> a >> b >> k;
  for(int i=1; i<=k; ++i)
  {
    if (i&1) {
      b+=(a/2);
      a>>=1;
    } else
    {
      a+=(b/2);
      b>>=1;
    }
  }
  cout << a << " " << b;
  return 0;
}