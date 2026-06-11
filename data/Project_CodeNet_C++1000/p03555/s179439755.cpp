#include <iostream>
using namespace std;

int main()
{
  string s, t, res = "YES";
  cin >> s >> t;
  for(int i=0; i<3; i++)
    if(s[i] != t[2-i])
      res = "NO";
  
  cout << res << endl;
  return 0;
}