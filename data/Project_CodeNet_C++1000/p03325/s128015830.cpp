#include<bits/stdc++.h>
using namespace std;

int two(int x)
{
  int r=0;
  while(x%2==0)
  {
    x/=2;
    r++;
  }
  return r;
}

int main()
{
  int n,ans;
  ans=0;
  cin>>n;
  vector<int> a(n);
  for(int i=0;i<n;i++)
  {
    cin>>a.at(i);
    ans+=two(a.at(i));
  }
  cout<<ans<<endl;
}