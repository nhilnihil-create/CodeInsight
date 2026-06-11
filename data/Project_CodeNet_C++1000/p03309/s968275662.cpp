#include<bits/stdc++.h>
using namespace std;

#define int long long int 

int32_t main()
{
  int n;
  cin>>n;
  int a[n];
  for(int i=1;i<=n;i++)
  {
    cin>>a[i-1];
    a[i-1]-=i;
  }
  sort(a,a+n);
  int ans=0;
  for(auto i:a)
  ans+=abs(i-a[n/2]);
  cout<<ans<<endl;
}