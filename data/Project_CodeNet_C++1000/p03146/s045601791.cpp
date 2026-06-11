#include "bits/stdc++.h"
using namespace std;

int main()
{
  int n,ans;
  ans=0;
  cin>>n;
  vector<int> v;
  v.push_back(n);
  for(int i=1;;i++)
  {
    if(n%2==0)
      n/=2;
    else
      n=n*3+1;
    v.push_back(n);
    for(int k=0;k<i;k++)
    {
      if(v.at(i)==v.at(k))
      {
        ans=i+1;
        break;
      }
    }
    if(ans!=0)
      break;
  }
  cout<<ans<<endl;
}