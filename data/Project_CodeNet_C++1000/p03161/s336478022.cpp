#include <bits/stdc++.h>
#define ll long long
using namespace std;

int dp[100005], a[100005];
int n,k;

int solve(int n, int k)
{
    dp[0]=0;
    for(int i=0; i<n; i++)
    {
        for(int j=1; j<=k && (i+j)<=n; j++)
        {
            dp[i+j]=min(dp[i+j], dp[i]+abs(a[i+j]-a[i]));
        }
    }
    return dp[n-1];

}
int main()
{
    cin>>n>>k;
    memset(dp, 1000000, sizeof(dp));
    for(int i=0; i<n; i++)
        cin>>a[i];
    cout<< solve(n,k) <<endl;
}

