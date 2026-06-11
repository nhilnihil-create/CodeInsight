#include <string>
#include <math.h>
#include <iostream>
 
using namespace std;
 
int main()
{
  string a;
  cin >> a;
  if (a == "000")
    cout << "0";
  else if (a == "001")
    cout << "1";
  else if (a == "010")
    cout << "1";
  else if (a == "100")
    cout << "1";
  else if (a == "101")
    cout << "2";
  else if (a == "110")
    cout << "2";
  else if (a == "011")
    cout << "2";
  else if (a == "111")
    cout << "3";
}