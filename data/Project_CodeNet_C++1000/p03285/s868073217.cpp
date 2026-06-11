#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll dp[101];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    dp[4]=1,dp[7]=1;
    for(int i=8;i<=100;i++)dp[i]=max(dp[i-4],dp[i-7]);
    ll n;
    cin>>n;
    if(dp[n])cout<<"Yes";
    else cout<<"No";
}
