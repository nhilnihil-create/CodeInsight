#include <iostream>

using namespace std;

int main()
{
  string s;
  cin >> s;
  if (s.size()==2) cout << s; else 
    for(int i=2; i>=0; --i) cout << s[i];
  return 0;
}