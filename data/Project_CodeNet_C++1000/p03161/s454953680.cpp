#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define inf 1000000000000000000
#define lli long long int
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lli n,k;
    cin>>n>>k;
    lli h[n], dp[n];
    for(int i=0; i<n; i++)
    {
        dp[i]=inf;
        cin>>h[i];
    }
    dp[0]=0, dp[1]=abs(h[1]-h[0]);
    for(int i=2; i<n; i++)
    {
        for(int j=i-1; j>=max(0LL, i-k); j--)
            dp[i]=min(dp[i], dp[j]+abs(h[i]-h[j]));
    }
    cout<<dp[n-1];
    return 0;
}