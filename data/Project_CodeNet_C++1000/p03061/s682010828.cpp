#include<bits/stdc++.h>
using namespace std;
#define ll                           long long
int main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(NULL);cout.tie(NULL);

      ll n,i;
      cin>>n;
      ll a[n];
      ll left[n],right[n];
      for(i=0;i<n;i++)
      {
        cin>>a[i];
      }
      sort(a,a+n);
      left[0]=a[0];
      right[n-1]=a[n-1];
      
      for(i=1;i<n;i++)
      {
        left[i]=__gcd(a[i],left[i-1]);
      }
      for(i=n-2;i>=0;i--)
      {
        right[i]=__gcd(a[i],right[i+1]);
      }

      

      ll ans=left[n-1];
      for(i=1;i<n-1;i++)
      {
        ans=max(ans,__gcd(left[i-1],right[i+1]));
      }
      ans=max(left[n-2],ans);
      ans=max(right[1],ans);
      cout<<ans<<endl;
}
