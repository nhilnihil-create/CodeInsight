#include<bits/stdc++.h>
using namespace std;
int n,k;
int arr[100004],dp[100006];

int dp_na_pari(int ind)
{
    if(ind==n-1) return 0;
    if(ind>=n) return INT_MAX;

    int ans=INT_MAX;
    if(dp[ind]!=-1)
        return dp[ind];

    for(int i=1;i<=2;i++)
    {
        if(ind+i<n)
          ans=min(ans,abs(arr[ind]-arr[ind+i])+ dp_na_pari(ind+i));
    }
    return dp[ind]=ans;

}

int main()
{

    cin>>n;
    memset(dp,-1,sizeof dp);
    for(int i=0;i<n;i++)cin>>arr[i];
    cout<<dp_na_pari(0)<<endl;

}
