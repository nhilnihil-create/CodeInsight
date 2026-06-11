#include<bits/stdc++.h>
using namespace std;

#define int long long int 

int32_t main()
{
    int n;
    cin>>n;
    int a[n+2],ans=0;
    a[0]=0;
    a[n+1]=0;
    for(int i=1;i<=n;i++)
     {
     cin>>a[i];
      ans+=abs(a[i]-a[i-1]);
     }
     ans+=abs(a[n]);
    
     
    int diff[n+2];
   
    diff[0]=0;
    diff[n+1]=0;
    for(int i=1;i<=n;i++)
       diff[i]=abs(a[i]-a[i-1])+abs(a[i+1]-a[i]);
    //     for(auto i:diff)
    // cout<<i<<" ";
    // cout<<endl;
    // cout<<ans<<endl;
    for(int i=1;i<n;i++)
     cout<<ans-diff[i]+abs(a[i+1]-a[i-1])<<endl;
     cout<<ans-abs(a[n-1]-a[n])-abs(a[n])+abs(a[n-1])<<endl;
    
    
}