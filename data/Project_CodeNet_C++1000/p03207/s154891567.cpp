#include<bits/stdc++.h>
using namespace std;

int main()
{
  int n,ans;
  ans=0;
  cin>>n;
  vector<int> p(n);
  for(int i=0;i<n;i++)
  {
    cin>>p.at(i);
  }
  sort(p.begin(),p.end());
  for(int i=0;i<n;i++)
  {
    if(i==n-1)
      p.at(i)/=2;
    ans+=p.at(i);
  }
  cout<<ans<<endl;
}