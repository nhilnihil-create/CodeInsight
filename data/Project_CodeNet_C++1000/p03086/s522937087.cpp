#include<iostream>
#include<algorithm>
using namespace std;
int main (void)
{
  int i,j,n,ans=0,cnt=0;
  string s;
  char a[4]={'A','T','C','G'};
  bool f;
  
  cin>>s;
  s=s+'0';
  n=s.size();
  for(i=0;i<n;i++)
  { 
    f=false;
    for(j=0;j<4;j++)
    {
      if(s[i]==a[j])f=true;
    }
    if(f==true){cnt++;}
    else 
    {
      if(ans<cnt)ans=cnt;
      cnt=0;
    }
  }
  cout<<ans<<endl;
  return 0;
}