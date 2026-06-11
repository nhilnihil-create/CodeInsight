#include "bits/stdc++.h"
using namespace std;

double z(double x)
{
  if(x>=0)
    return x;
  else
    return x*-1;
}

int main()
{
  double n,t,a,ans;
  ans=1000000;
  cin>>n>>t>>a;
  vector<double> h(n);
  for(int i=0;i<n;i++)
  {
    cin>>h.at(i);
    h.at(i)=z(a-(t-h.at(i)*0.006));
    ans=min(ans,h.at(i));
  }
  for(int i=0;i<n;i++)
  {
    if(h.at(i)==ans)
    {
      cout<<i+1;
      break;
    }
  }
}