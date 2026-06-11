#include<bits/stdc++.h>
using namespace std;

#define int long long int 

int32_t main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
      cin>>a[i];
      sort(a,a+n);
      reverse(a,a+n);
      int ans=0;
      for(int i=0;i<n;i++)
      {
          if(i%2==0)
          ans+=a[i];
          else
          ans-=a[i];
      }
      cout<<ans<<endl;
}