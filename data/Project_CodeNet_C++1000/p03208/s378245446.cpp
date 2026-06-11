#include <iostream>
#include<algorithm>
using namespace std;
int main(void)
{
  int i,n,k,h[100000],ans=1000000001;
  cin>>n>>k;
  for(i=0;i<n;i++)
  {
    cin>>h[i];
  
  }
  sort(h,h+n);
  for(i=0;i<n-k+1;i++)
  {
    if(h[i+k-1]-h[i]<ans){ans=h[i+k-1]-h[i];}
  
  }
  
  cout<<ans<<endl;
}