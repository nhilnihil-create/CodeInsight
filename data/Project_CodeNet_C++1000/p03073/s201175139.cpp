#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long long INF = 1LL << 60;

int main()
{
  string s;
  int a,b;
  a=0;
  b=0;
  cin>>s;
  for(int i=0;i<s.size();i++)
  {
    if(i%2==0)
    {
      if(s.at(i)=='1')
        a++;
    }
    else
    {
      if(s.at(i)=='0')
        a++;
    }
  }
  for(int i=0;i<s.size();i++)
  {
    if(i%2==0)
    {
      if(s.at(i)=='0')
        b++;
    }
    else
    {
      if(s.at(i)=='1')
        b++;
    }
  }
  cout<<min(a,b)<<endl;
}