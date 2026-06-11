#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin>>n;
  
  vector<int>h(n);
  for(int i=0;i<n;i++)cin>>h[i];
  
  long long ans=0;
  
  for(int i=0;i<n;i++)
  {
    if(i==0)ans+=h[i];
    else 
    {
      if(h[i]>h[i-1])
      {
        ans+=(h[i]-h[i-1]);
      }
    }
  }
  cout<<ans<<endl;
  return 0;
}
        
        
    