#include<bits/stdc++.h>
using namespace std;
int a[100001],dp[100001];
int solve(int n)
{
    dp[0]=0;
    dp[1]=abs(a[0]-a[1]);
    for(int i=2;i<n;i++)
    {
        int d=abs(a[i]-a[i-1]);
        int e=abs(a[i]-a[i-2]);
        dp[i]=min(dp[i-2]+e,dp[i-1]+d);
    }
    return dp[n-1];
}
int main()
{
    int n;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    cout << solve(n) << endl;
}