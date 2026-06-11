#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main()
{
  string s;
  cin >> s;
  if((s[0] == 'a' && ((s[1] == 'b' && s[2] == 'c') || (s[1] == 'c' && s[2] == 'b'))) ||
     (s[0] == 'b' && ((s[1] == 'a' && s[2] == 'c') || (s[1] == 'c' && s[2] == 'a'))) ||
     (s[0] == 'c' && ((s[1] == 'b' && s[2] == 'a') || (s[1] == 'a' && s[2] == 'b'))) )
    cout << "Yes";
  else
    cout << "No";
  return 0;
}
