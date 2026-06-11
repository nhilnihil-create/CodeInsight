#include<iostream>
#include<bits/stdc++.h>
#define rep(i,n) for(i=0;i<n;i++)
#define pb push_back
#define lli long long int
#define all(v) (v.begin(),v.end())
#define fr first
#define sc second
#define mp make_pair
using namespace std;
int a[100];

int main()
{
    int n,i,j,k;
    cin>>n>>k;
    int a[n];
    rep(i,n) cin>>a[i];
    int dp[n+1];
    for(i=0;i<n;i++) dp[i]=INT_MAX;
    dp[0]=0;
    dp[1]=abs(a[1]-a[0]);
    for(i=2;i<n;i++)
    {
        for(j=1;j<=k;j++)
        {
            if(i-j>=0) dp[i]=min(dp[i-j]+abs(a[i]-a[i-j]),dp[i]);
        }

    }
    cout<<dp[n-1]<<endl;
}
