/* BISMILLAHIR RAHMANIR RAHIM */
#include<bits/stdc++.h>
#define INF 9999999
#define ll long long
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n,k;
    cin>>n>>k;
    int dp[n];
    vector<int>ar(n);
    for(int i=0; i<n; i++)
        cin>>ar[i];

    dp[0]=0;
      for(int i=1; i<n; i++)
    {
       dp[i]=INT_MAX;
        for(int j=1; j<=k; j++)
        {
            if(i-j>=0)
                dp[i]=min(dp[i],dp[i-j]+abs(ar[i]-ar[i-j]));
        }
    }
    cout<<dp[n-1];
    return 0;
}
