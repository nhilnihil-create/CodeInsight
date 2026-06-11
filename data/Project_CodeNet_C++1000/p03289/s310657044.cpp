#include "bits/stdc++.h"
using namespace std;

int main()
{
  string s,ans;
  int c,p,n;
  c=0;
  cin>>s;
  n=s.size();
  ans="AC";
  if(s.at(0)!='A')
    ans="WA";
  else
  {
    s.at(0)='a';
    for(int i=2;i<n-1;i++)
    {
      if(s.at(i)=='C')
      {
        c++;
        p=i;
      }
    }
    if(c!=1)
      ans="WA";
    else
    {
      s.at(p)='a';
      for(int i=0;i<n;i++)
      {
        if((s.at(i)<=96)||(s.at(i)>=123))
        {
          ans="WA";
          break;
        }
      }
    }
  }
  cout<<ans<<endl;
}