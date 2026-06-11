#include "bits/stdc++.h"
using namespace std;

int main()
{
  int n,t,ans;
  ans=2000;
  cin>>n>>t;
  vector<int> c(n);
  vector<int> tt(n);
  for(int i=0;i<n;i++)
  {
    cin>>c.at(i)>>tt.at(i);
    if(tt.at(i)<=t)
      ans=min(ans,c.at(i));
  }
  if(ans!=2000)
    cout<<ans<<endl;
  else
    cout<<"TLE"<<endl;
}