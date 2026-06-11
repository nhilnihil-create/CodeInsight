#include<iostream>
#include<string>
using namespace std;

int main()
{
  string s;
  cin >> s;
  
  int l = s.size();
  
  char first, second;
  if (s.at(0) == '0')
  {
    first = '0';
    second = '1';
  }
  else
  {
    first = '1';
    second = '0';
  } 
  
  int count = 0;
  for (int i = 0; i < l; i ++)
  {
    if (i % 2 == 0)
    {
      if (s.at(i) != first)
        count ++;
    }
    else
    {
      if (s.at(i) != second)
        count ++;
    }
  }
  
  cout << count;
  return 0;
}