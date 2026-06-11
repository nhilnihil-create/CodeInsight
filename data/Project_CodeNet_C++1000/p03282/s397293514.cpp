#include "bits/stdc++.h"
using namespace std;

int main()
{
  string s;
  int64_t k;
  cin>>s>>k;
  if(s.at(0)!=49)
  {
    cout<<s.at(0)-48<<endl;
  }
  else
  {
    int one=0;
    int x;
    for(int i=0;i<s.size();i++)
    {
      if(s.at(i)==49)
        one++;
      else
        {
          x=s.at(i)-48;
          break;
        }
    }
    if(one>=k)
      cout<<1<<endl;
    else
      cout<<x<<endl;
  }
}