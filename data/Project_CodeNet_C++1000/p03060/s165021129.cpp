#include<bits/stdc++.h>
#define ll long long int
#define ff first
#define ss second
#define eps 1e-9

using namespace std;

int main()
{

    ll t,n,m,f,a,b,c,l,r,q,k,x,y,z,ans,mn,mx,sum=0;

    cin>>n;

    vector< pair<ll,ll> > arr(n);

    for(int i=0;i<n;i++)
    {
        cin>>arr[i].ff;
    }

    for(int i=0;i<n;i++)
    {
        cin>>arr[i].ss;
    }

    sort(arr.begin(),arr.end(),[](auto &a,auto &b)
         {
             return (a.ff-a.ss) > (b.ff-b.ss);
         });

         x=y=0;
         ans=0;
         for(int i=0;i<n;i++)
         {
             x+=arr[i].ff;
             y+=arr[i].ss;

             ans = max(ans,x-y);
         }

         cout<<ans<<endl;


}
