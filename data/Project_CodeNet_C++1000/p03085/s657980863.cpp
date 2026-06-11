#include <iostream>
#include <string>
using namespace std;

int main()
{
  string s;
  cin >> s;
  if(s == "A") cout << "T";
  if(s == "T") cout << "A";
  if(s == "C") cout << "G";
  if(s == "G") cout << "C";
  return 0;
}