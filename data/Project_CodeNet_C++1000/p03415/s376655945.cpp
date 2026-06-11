#include <iostream>
using namespace std;

int main()
{
  string s, res;
  for(int i = 0; i < 3; i++)
  {
    cin >> s;
    res += s[i];
  }
  cout << res << endl;
  return 0;
}