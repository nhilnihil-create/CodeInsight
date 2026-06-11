#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;
    int a[n];
    cin>>a[0]>>a[1];
    int dp[n];
    int mn;
    dp[0]=0;dp[1]=abs(a[1]-a[0]);
    for(int i=2;i<n;i++)
    {
        cin>>a[i];
        mn=dp[i-1]+abs(a[i]-a[i-1]);
        for(int j=2;j<=k && j<=i;j++)
        {
            if(mn>dp[i-j]+abs(a[i]-a[i-j])) mn=dp[i-j]+abs(a[i]-a[i-j]);
        }
        dp[i]=mn;
    }
    cout<<dp[n-1];
    return 0;
}
