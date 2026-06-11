#include <iostream>
#include <string>
#include <cmath>

using namespace std;

bool isacgt(char c)
{
  return (   c == 'A' 
          || c == 'C'
          || c == 'G'
          || c == 'T' );
}

int main()
{
  string s; cin >> s;
  int maxlen = 0;
  int len = 0;
  for (int i = 0; i < s.size(); i++)
  {
    if (isacgt(s[i])) len++;
    else len = 0;
    maxlen = max(len, maxlen);
  }
  cout << maxlen << endl;
}