#include<iostream>
#include<algorithm>
using namespace std;
int main (void)
{
  string s,t;
  cin>>s>>t;
  int i,j,n=s.size();
  s=s+s;
   bool f;
  for(i=0;i<n;i++)
  {
    f=true;
    for(j=0;j<n;j++)
    {
      if(s[i+j]!=t[j]){f=false;break;}
    }
    if(f==true){cout<<"Yes"<<endl;return 0;}
  }
  cout<<"No"<<endl;
  return 0;
  
}