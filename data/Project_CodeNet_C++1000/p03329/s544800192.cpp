#include<bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin>>n;
  int ans=n;
  for(int i=0;i<=n;i++)
  {
    int temp=0;
    int t=i;
	while(t>0)
    {
		temp+=(t%6);
      	t/=6;
    }
    t=n-i;
    while(t>0)
    {
      temp+=(t%9);
      t/=9;
    }
    ans=min(ans,temp);
  }
  cout<<ans<<endl;
  return 0;
}