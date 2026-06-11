#include "bits/stdc++.h"
using namespace std;

int64_t z(int64_t x)
{
  if(x>=0)
    return x;
  else
    return x*-1;
}

int main()
{
  int64_t n,k,ans;
  ans=1000000000;
  cin>>n>>k;
  vector<int64_t> h(n);
  for(int i=0;i<n;i++)
  {
    cin>>h.at(i);
  }
  sort(h.begin(),h.end());
  for(int i=0;i<=n-k;i++)
  {
    ans=min(ans,z(h.at(i)-h.at(i+k-1)));
  }
  cout<<ans<<endl;
}