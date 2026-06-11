#include<bits/stdc++.h>
using namespace std;

int main()
{
  string s,t;
  int f=0;
  cin>>s>>t;
  for(int i=0;i<s.size();i++)
  {
    char h=s.at(s.size()-1);
    for(int j=s.size()-1;j>=1;j--)
    {
      s.at(j)=s.at(j-1);
    }
    s.at(0)=h;
    if(s==t)
    {
      f=1;
      break;
    }
  }
  if(f==1)
    cout<<"Yes"<<endl;
  else
    cout<<"No"<<endl;
}