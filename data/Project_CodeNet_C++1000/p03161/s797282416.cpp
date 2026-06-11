#include <bits/stdc++.h>
//#include<string>
using namespace std;


int main()
{
    int n,k;
    cin>>n>>k;
    vector<int> ar(n,0);
    for(int i=0;i<n;++i)
    cin>>ar[i];
    vector<int> dp(n,INT32_MAX);
    dp[0]=0;
    for(int i=1;i<n;++i)
    {
        for(int j=max(i-k,0);j<i;++j)
        {
            dp[i]=min(dp[i],dp[j]+abs(ar[i]-ar[j]));
        }
    }
   cout<<dp[n-1]<<'\n';
 }

