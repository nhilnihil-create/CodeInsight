#include<bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp> 
//using namespace boost::multiprecision; 

using namespace std;

//#Rohitpratap311
//#Keep Calm And Stay Happy

typedef long long ll;
typedef long double ld;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t=1;
    //cin>>t;
    while(t--)
    {
        ll n,k;
        cin>>n>>k;
        ll arr[n];
        for(ll i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        ll dp[n];
        for(ll i=0;i<n;i++) { dp[i]=1e18; }
        dp[0]=0; dp[1]=abs(arr[1]-arr[0]);
       // cout<<dp[0]<<endl<<dp[1]<<endl;
        for(ll i=2;i<=min(k,n);i++)
        {
            for(ll j=i-1;j>=0;j--)
            {
                ll temp=abs(arr[i]-arr[j])+dp[j];
                dp[i]=min(dp[i],temp);
            }
            //cout<<dp[i]<<endl;
        }
        for(ll i=k+1;i<n;i++)
        {
            for(ll j=1;j<=k;j++)
            {
                ll temp=abs(arr[i]-arr[i-j])+dp[i-j];
                dp[i]=min(dp[i],temp);
            }
            //cout<<dp[i]<<endl;
        }
        cout<<dp[n-1];
        
    }
    return 0;
}