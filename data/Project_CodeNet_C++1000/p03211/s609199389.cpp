#include<iostream>
#include<algorithm>
using namespace std;
int main (void)
{
  string s;
  cin>>s;
  int i,n,ans=1000,sum;;
  n=s.size();
  for(i=0;i<n-2;i++)
  {
    sum=0;
    sum+=(s[i]-'0')*100;
    sum+=(s[i+1]-'0')*10;
    sum+=s[i+2]-'0';
    ans=min(ans,abs(sum-753));
  }
  cout<<ans<<endl;
}