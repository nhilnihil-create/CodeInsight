#include<bits/stdc++.h>
using namespace std;

int main()
{
  string s;cin>>s;
  int n;
  n=s.length();
  char cent=s.at(n/2);
  int ans;
  if(n%2==0)
  {
    int hb=0;
    while(n/2+hb<n)
    {
      if(s.at(n/2-(hb+1))!=cent||s.at(n/2-1+(hb+1))!=cent)break;
      hb++;
    }
    ans=n/2+hb;
  }
  else
  {
    int hb=0;
    while(n/2+hb+1<n)
    {
      if(s.at(n/2-(hb+1))!=cent||s.at(n/2+(hb+1))!=cent)break;
      hb++;
    }
    ans=n/2+1+hb;
  }
  cout<<ans<<endl;
}