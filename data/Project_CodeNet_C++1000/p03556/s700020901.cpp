#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
  int n,ans=0;
  cin>>n;
  for(int i=1;i<100000000;i++)
  {
    if(i*i<=n) ans=max(ans,i*i);
    else break;
  }
  cout<<ans;
}