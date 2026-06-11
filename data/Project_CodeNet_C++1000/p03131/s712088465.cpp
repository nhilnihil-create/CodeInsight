#include<bits/stdc++.h>
using namespace std;
int main()
{
  long long k,a,b;
  cin>>k>>a>>b;
  if((a+2)>b || k<(a+1))
  {
    cout<<k+1<<endl;
  }
  else
  {
    long long ans=b;
    k-=(a+1);
    long long n=k/2;
    ans+=n*(b-a)+(k%2);
    cout<<ans<<endl;
  }
  return 0;
}
    