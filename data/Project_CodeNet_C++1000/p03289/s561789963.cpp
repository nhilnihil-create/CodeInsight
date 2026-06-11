#include<iostream>
#include<string>
using namespace std;

int main()
{
  string s;
  cin >> s;
  
  if (!(s.at(0) == 'A' && s.at(1) >= 'a'))
  {
    cout << "WA";
    return 0;
  }
  
  bool Ced = false;
  for (int i = 2; i < s.size(); i ++)
  {
    if (s.at(i) == 'C')
    {
      if (!Ced) 
      {
        if (i != s.size() - 1)
          Ced = true;
        else
        {
          cout << "WA";
          return 0;
        }
      }
      else
      {
        cout << "WA";
        return 0;
      }
    }
    else if (s.at(i) < 'a')
    {
      cout << "WA";
      return 0;
    }
  }
  
  if (!Ced)
    cout << "WA";
  else
    cout << "AC";
  return 0;
}
