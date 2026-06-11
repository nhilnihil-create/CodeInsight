#include<iostream>
#include<string>
using namespace std;

int main()
{
  int a, b;
  string s;
  cin >> a >> b;
  cin >> s;
  
  if (s.at(a) != '-')
  {
    cout << "No";
    return 0;
  }
  
  for (int i = 0; i < s.size(); i ++)
  {
    if (s.at(i) == '-' && i != a)
    {
      cout << "No";
      return 0;
    }
  }
  
  cout << "Yes";
  return 0;
}