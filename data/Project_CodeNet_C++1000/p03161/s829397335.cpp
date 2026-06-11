#include <bits/stdc++.h>
using namespace std;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, k;
    cin>>n>>k;
    vector<int> h(n);
    for(int i = 0;i<n;i++)
    {
        cin>>h[i];
    }
    vector<int> dp(n, INT_MAX);
    dp[0] = 0;
    if(n == 1)
    {
        cout<<0<<"\n";
        return 0;
    }
    for(int i = 1;i<n;i++)
    {
        int j = max(0, i-k);
        for(;j<i;j++)
        {
            dp[i] = min(dp[i], abs(h[i]- h[j]) + dp[j]);
        }
    }
    cout<<dp[n-1]<<"\n";
    return 0;
}