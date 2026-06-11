#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define hell 1000000007
#define PI 3.14159265358979323846
#include <fstream>
using namespace std;

int main()
{
    //  freopen("timber_input.txt", "r", stdin);
   // freopen("out3_test.txt", "w", stdout);
   ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
   // cin>>t;
    while(t--) {
    ll n,i,j,k;
    cin>>n>>k;
    ll arr[n+1],dp[n+1];

    for(i=0;i<n;i++)
        cin>>arr[i];
    dp[0]=0;
    dp[1]=abs(arr[1]-arr[0]);
    for(i=2;i<n;i++)
    {
        dp[i]=hell;
        for(j=i-1;j>=max(0ll,i-k);j--)
            dp[i]=min(dp[i],abs(arr[i]-arr[j])+dp[j]);
    }
    cout<<dp[n-1];
    }

}
