#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

int main()
{
  int count = 0;
  string s;
  cin >> s;
  
  for(int i = 0; i < 3; i++)
  {
    for(int j = 0; j < 3; j++)
    {
      if(s[i] == s[j])
      {
        count++;
      }
    }
  }
  
  if(count > s.size())
  {
    cout << "No";
  }
  else
  {
    cout << "Yes";
  }
}