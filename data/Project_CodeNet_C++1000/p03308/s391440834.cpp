#include<iostream>
#include<algorithm>
using namespace std;
int main (void)
{
  int a[100],i,n,ans;
  cin>>n;
  for(i=0;i<n;i++){cin>>a[i];}
  sort(a,a+n);
  ans=a[n-1]-a[0];
  cout<<ans<<endl;
  return 0;
  
  
}