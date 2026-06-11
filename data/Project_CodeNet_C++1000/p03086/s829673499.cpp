#include <iostream>
#include <string>
using namespace std;

int main()
{
  string s;
  cin >> s;
  int res = 0, cnt = 0;
  
  for(int i=0; i<s.size(); i++)
  {
    if(s[i] == 'A' ||
      s[i] == 'C' ||
      s[i] == 'G' ||
      s[i] == 'T')
    {
      cnt++;
    }
    else
    {
      res = max(res, cnt);
      cnt = 0;
    }
  }
  
  res = max(res, cnt);
  
  cout << res << endl;
  return 0;
}