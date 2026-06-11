#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
  string s;
  cin >> s;
  
  int acgt = 0;
  int ans = 0;
  for(int i = 0; i < s.length(); ++i)
  {
    if(s[i] == 'A' || s[i] == 'C' || s[i] == 'G' || s[i] =='T')
    {
      acgt++;
    }
    else
    {
      ans = max(ans, acgt);
      acgt = 0;
    }
  }
  
  ans = max(ans, acgt);
  cout << ans << endl;
}