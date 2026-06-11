#include<bits/stdc++.h>
using namespace std;
int a[100001],dp[100001];
int solve(int n,int k)
{
    dp[0]=0;
    dp[1]=abs(a[0]-a[1]);
    for(int i=2;i<n;i++)
    {
        int c;
        int d=INT_MAX;
        for(int j=max(0,i-k);j<i;j++)
        {
            c=dp[j]+abs(a[i]-a[j]);
            d=min(c,d);
        }
        dp[i]=d;
    }
    return dp[n-1];
}
int main()
{
    int n,k;
    cin >> n >> k;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    cout << solve(n,k) << endl;
}