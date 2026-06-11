#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n;
  cin>>n;
  vector<vector<int> >f(n);
  for(int i=0;i<n;i++)
  {
    f[i].resize(10);
    for(int j=0;j<10;j++)cin>>f[i][j];
  }
  vector<vector<int> >p(n);
  for(int i=0;i<n;i++)
  {
    p[i].resize(11);
    for(int j=0;j<11;j++)cin>>p[i][j];
  }
  long long ans=0;
  for(int i=1;i<=1023;i++)
  {
    long long count=0;
    for(int j=0;j<n;j++)
    {
      int t=0;
      for(int k=0;k<10;k++)
      {
        if((i&(1<<k))!=0 && f[j][9-k]==1)t++;
      }
      count+=p[j][t];
    }
    //cout<<count<<endl;
    if(i==1)ans=count;
    else if(ans<count)ans=count;
  }
 cout<<ans<<endl;
  return 0;
}