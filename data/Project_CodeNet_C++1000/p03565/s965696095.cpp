#include <iostream>
#include <string>

using namespace std;

int main()	{
  string s;
  string t;
  cin >> s >> t;
  if (s.length() < t.length())	{
    cout << "UNRESTORABLE" << endl;
    return 0;
  }
  bool doable = false;
  for (int i = s.length() - t.length(); i >= 0; i--)	{
    //try string matching
    bool failed = false;
    for (int j = i; j < i + t.length() && j < s.length(); j++)	{
      if (s[j] != '?' && s[j] != t[j - i])	{
        failed = true;
        break;
      }
    }
    if (!failed)	{
      doable = true;
      for (int j = i; j < i + t.length(); j++)	{
        s[j] = t[j - i];
      }
      for (int j = 0; j < s.length(); j++)	{
        if (s[j] == '?')	{
          s[j] = 'a';
        }
      }
    }
  }
  if (!doable)	{
    cout << "UNRESTORABLE" << endl;
    return 0;
  }
  cout << s << endl;
  return 0;
}