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
    cin>>n;
    ll arr[n+1],brr[n+1],crr[n+1],dp[n+1][3];

    for(i=0;i<n;i++)
        cin>>arr[i]>>brr[i]>>crr[i];


    dp[0][0]=arr[0];
    dp[0][1]=brr[0];
    dp[0][2]=crr[0];
    for(i=1;i<n;i++)
    {
        dp[i][0]=max(dp[i-1][1],dp[i-1][2])+arr[i];
        dp[i][1]=max(dp[i-1][0],dp[i-1][2])+brr[i];
        dp[i][2]=max(dp[i-1][0],dp[i-1][1])+crr[i];
    }
    cout<<max(dp[n-1][0],max(dp[n-1][1],dp[n-1][2]));
    }

}
