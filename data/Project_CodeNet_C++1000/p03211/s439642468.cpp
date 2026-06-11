#include "bits/stdc++.h"
using namespace std;

int z(int x)
{
  if(x>=0)
    return x;
  else
    return x*-1;
}

int main()
{
  string s;
  cin>>s;
  int ans=1000;
  for(int i=0;i<=s.size()-3;i++)
  {
    int x;
    x=(s.at(i)-48)*100+(s.at(i+1)-48)*10+(s.at(i+2)-48);
    ans=min(ans,z(x-753));
  }
  cout<<ans<<endl;
}