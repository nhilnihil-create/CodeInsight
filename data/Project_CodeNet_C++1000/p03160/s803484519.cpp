#include <bits/stdc++.h>
using namespace std;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin>>n;
    vector<int> h(n);
    for(int i = 0;i<n;i++)
    {
        cin>>h[i];
    }
    vector<int> dp(n, INT_MAX);
    dp[0] = 0;
    if(n == 1)
    {
        cout<<dp[0]<<"\n";
        return 0;
    }
    dp[1] = abs(h[0] - h[1]);
    if(n == 2)
    {
        cout<<dp[1]<<"\n";
        return 0;
    }
    for(int i = 2;i<n;i++)
    {
        dp[i] = min(abs(h[i] - h[i-1]) + dp[i-1], abs(h[i] - h[i-2]) + dp[i-2]);
    }
    cout<<dp[n-1]<<"\n";
    return 0;
}