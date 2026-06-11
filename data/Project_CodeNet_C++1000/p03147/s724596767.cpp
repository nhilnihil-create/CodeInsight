#include "bits/stdc++.h"
using namespace std;

int main()
{
  int n,t,ans;
  ans=0;
  t=0;
  cin>>n;
  vector<int> h(n);
  for(int i=0;i<n;i++)
  {
    cin>>h.at(i);
    t=max(t,h.at(i));
  }
  for(int i=0;i<t;i++)
  {
    for(int j=0;j<n;j++)
    {
      if(j==0)
      {
        if(h.at(j)>0)
          ans++;
      }
      else
      {
        if(h.at(j)>0)
        {
          if(h.at(j-1)<=0)
            ans++;
        }
      }
    }
    for(int j=0;j<n;j++)
    {
      h.at(j)--;
    }
  }
  cout<<ans<<endl;
}