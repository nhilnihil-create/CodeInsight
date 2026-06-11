#include <iostream>

#define int64 unsigned long long

using namespace std;

int main()
{
  int64 xx, yy;
  cin >> xx >> yy;
  for(int64 ii = 1;true;ii++)
  {
    if((xx << ii) >yy)
    {
      cout << ii << endl;
      return 0;
    }
  }
}