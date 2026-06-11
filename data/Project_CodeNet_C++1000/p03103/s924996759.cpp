#include "bits/stdc++.h"
using namespace std;

int main()
{
  int64_t n,m,ans,h;
  ans=0;
  h=0;
  cin>>n>>m;
  vector<pair<int64_t,int64_t>> a(n);
  for(int i=0;i<n;i++)
  {
    cin>>a.at(i).first>>a.at(i).second;
  }
  sort(a.begin(),a.end());
  for(int i=0;i<n;i++)
  {
    ans+=a.at(i).first*a.at(i).second;
    h+=a.at(i).second;
    if(h>m)
    {
      ans-=a.at(i).first*(h-m);
      break;
    }
  }
  cout<<ans<<endl;
}