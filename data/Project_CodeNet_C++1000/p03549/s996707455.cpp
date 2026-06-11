#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n,m;
  cin>>n>>m;
  long long t=((n-m)*100)+(m*1900);
  long long ans=t*pow(2,m);
  cout<<ans<<endl;
  return 0;
}
    
  