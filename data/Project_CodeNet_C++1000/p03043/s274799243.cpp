#include "bits/stdc++.h"
using namespace std;

int two(int x,int y)
{
  int r=0;
  while(x<y)
  {
    x*=2;
    r++;
  }
  return r;
}

double rui(int x)
{
  double r=1;
  for(int i=0;i<x;i++)
  {
    r/=2;
  }
  return r;
}

int main()
{
  int n,k;
  double ans=0;
  cin>>n>>k;
  for(int i=1;i<=n;i++)
  {
    ans+=rui(two(i,k))/n;
  }
  cout<<fixed<<setprecision(10);
  cout<<ans<<endl;
}