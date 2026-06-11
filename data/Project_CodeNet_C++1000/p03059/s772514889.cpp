#include <iostream>

using namespace std;

int main()
{
  int a,b,t;
  int ans=0;
  cin>>a>>b>>t;
  int T=a;
  while(T<=t)
  {
    ans+=b;
    T+=a;
  }
  cout<<ans<<endl;
    return 0;
}