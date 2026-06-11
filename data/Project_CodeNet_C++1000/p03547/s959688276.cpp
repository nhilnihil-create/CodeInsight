#include <iostream>

using namespace std;

int main()	{
  char x, y;
  cin >> x >> y;
  if (x > y)	{
    cout << ">" << endl;
  }
  else if (y > x)	{
    cout << "<" << endl;
  }
  else	{
    cout << "=" << endl;
  }
  return 0;
}