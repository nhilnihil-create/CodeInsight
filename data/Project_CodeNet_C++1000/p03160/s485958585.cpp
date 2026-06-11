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
        ll n;
        cin>>n;
        ll arr[n];
        for(ll i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        ll dp[n];
        dp[0]=0;
        dp[1]=abs(arr[1]-arr[0]);
        for(ll i=2;i<n;i++)
        {
            ll a=abs(arr[i]-arr[i-1])+dp[i-1];
            ll b=abs(arr[i]-arr[i-2])+dp[i-2];
            dp[i]=min(a,b);
            //cout<<dp[i]<<endl;
        }
        cout<<dp[n-1];
    }
    return 0;
}