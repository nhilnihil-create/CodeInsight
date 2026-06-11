#include<bits/stdc++.h>
using namespace std;
int td(int n,vector<int> a,int k)
{
    vector<int> dp(n+1);
    dp[1]=0;
    for(int i=2;i<=n;i++)
    {
        dp[i]=INT_MAX;
        for(int j=i-1;j>=1 && (i-j)<=k;j--)
        {
           //cout<<"++";
           dp[i]=min(dp[i],abs(a[i]-a[j])+dp[j]);
        }
    }
    return dp[n];
}
int main()
{
    int n,k;
    cin>>n>>k;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++)
        cin>>a[i];
    cout<<td(n,a,k);
}
