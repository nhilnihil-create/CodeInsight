#include<iostream>
using namespace std;
int main()
{
  int a,b,t,ans=0;
  cin>>a>>b>>t;
  for(int i=a;i<=t;i+=a)
    ans+=b;
  cout<<ans;
}
