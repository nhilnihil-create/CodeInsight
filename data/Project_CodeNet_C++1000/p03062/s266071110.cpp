#include<bits/stdc++.h>
using namespace std;
#define ll                           long long

int main()
{
      ll n;
      cin>>n;
      ll a[n];
      ll i;
      ll mini=1e9+1,c=0,sum=0;
      for(i=0;i<n;i++)
      {
        cin>>a[i];
        if(a[i]<0)
            c++;
        sum+=abs(a[i]);
        mini=min(mini,abs(a[i]));
      }
      if(c%2==0)
      {
        cout<<sum<<endl;
      }
      else
      {
        cout<<sum-2*mini<<endl;
      }

}