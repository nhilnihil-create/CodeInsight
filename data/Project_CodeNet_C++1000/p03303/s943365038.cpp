#include <iostream>
#include <string>

using namespace std;

int main()
{
  string s;
  cin >> s;
  int k;
  cin >> k;
  int i=0;
  while(i<s.size())
  {
    cout << s[i];
    i+=k;
  }
  
  return 0;
}