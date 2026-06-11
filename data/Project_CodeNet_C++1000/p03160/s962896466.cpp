#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = 1000000007;
const int INF = 1e9 +5;
long long int mem[5001] = {INT_MIN};

int main()
{
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ll int n,i;
    cin>>n;
    vector<ll int> h(n,0);
    vector<ll int> dp(n,INF);
    for(i=0;i<n;i++)
        cin>>h[i];
    dp[0]=0;
    for(i=0;i<n;i++)
    {
        for(int j=i+1;j<=i+2 && j<n;j++)
            dp[j]=min(dp[j],dp[i]+abs(h[j]- h[i]));
    }
    cout<<dp[n-1];
    return 0;
}