#include<iostream>
using namespace std;

void insertSort(string &s, bool des = false)
{
  //挿入ソート
  for(int i = 1; i < s.size(); i++)
  {
    for(int j = i; j > 0; j--)
    {
      char a = s[j];
      if(!des)
      {
        if(s[j - 1] > a)
        {
          s[j] = s[j - 1];
          s[j - 1] = a;
        }
      }
      else
      {
        if(s[j - 1] < a)
        {
          s[j] = s[j - 1];
          s[j - 1] = a;
        }
      }
    }
  }
}

int main()
{
  bool res = false, isEqual = true;
  string s, t;
  cin >> s >> t;
  insertSort(s);
  insertSort(t, true);
  int length = (s.size() > t.size())? t.size(): s.size();
  for(int i = 0; i < length; ++i)
  {
    if(s[i] < t[i])
    {
      res = true;
      break;
    }
  }
  
  //if(!res && isEqual && s.size() < t.size())
  if(!res && s.size() < t.size())
  {
    for(int i = 0; i < length; i++)
    {
      if(s[i] != t[i])
      {
        isEqual = false;
      }
    }
    
    if(isEqual)
      res = true;
  }
  
  if(res)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  
  return 0;
}