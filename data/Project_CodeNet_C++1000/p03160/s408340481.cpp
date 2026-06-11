#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back

int main()
{
    ll n;
    cin>>n;
    vector<ll> arr(n),dp(n,INT_MAX);
    for(int i=0;i<n;i++)
      cin>>arr[i];

    dp[0]=0;
    dp[1]=abs(arr[1]-arr[0]);
    for(int i=1;i<n;i++)
    {
      dp[i]=min(abs(arr[i]-arr[i-1])+dp[i-1],abs(arr[i]-arr[i-2])+dp[i-2]);
    }

    cout<<dp[n-1]<<endl;
}
