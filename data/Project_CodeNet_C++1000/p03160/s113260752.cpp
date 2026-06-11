#include<bits/stdc++.h>
using namespace std;
int td(int n,vector<int> a)
{
    vector<int> dp(n+1);
    dp[1]=0;
    dp[2]=abs(a[1]-a[2]);
    for(int i=3;i<=n;i++)
    {
        dp[i]=min(abs(a[i]-a[i-1])+dp[i-1],abs(a[i]-a[i-2])+dp[i-2]);
    }
    return dp[n];
}
int main()
{
    int n;
    cin>>n;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++)
        cin>>a[i];
    cout<<td(n,a);
}
