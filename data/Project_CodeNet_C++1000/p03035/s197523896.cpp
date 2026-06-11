#include <iostream>
using namespace std;

int main()
{
  int year, cost;

  cin >> year >> cost;

  if(year <= 12 && year > 5)
  {
    cout << cost / 2 << endl;
  }

  else if(year <=5)
  {
    cout << 0 << endl;
  }

  else
  cout << cost << endl;
}
