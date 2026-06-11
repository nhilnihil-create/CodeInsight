#include<iostream>
#include<algorithm>
using namespace std;
int main (void)
{
  int i,j,n,ans=0,cnt=0;
  int a,b[20],m,c;
  cin>>n>>m>>c;
  for(i=0;i<m;i++)cin>>b[i];
  for(i=0;i<n;i++)
  {
    for(j=0;j<m;j++)
    {
      cin>>a;
      ans+=(a*b[j]);
    }  
    ans+=c;
    if(ans>0)cnt++;
    ans=0;
  }
  cout<<cnt<<endl;
  return 0;
}