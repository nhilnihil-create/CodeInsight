#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int main()
{
  string day;
  cin >> day;
  const char mon[2] = {day[5], day[6]};
  if(atoi(mon) < 5)
  {
    cout << "Heisei" << endl;
  }
  else
  {
    cout << "TBD" << endl;
  }
  return 0;
}