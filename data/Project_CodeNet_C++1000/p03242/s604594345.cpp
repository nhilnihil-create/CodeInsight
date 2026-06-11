#include<bits/stdc++.h>
using namespace std;

int main()
{
  string str;
  cin>>str;
  for(int i = 0; i < str.size(); i++)
  {
    if(str[i]=='1')
    {
      str[i] = '9';
    }
    else 
    {
      str[i] = '1';
    }
  }
  cout<<str;
}