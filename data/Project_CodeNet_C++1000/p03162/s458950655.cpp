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
    lli n;
    cin>>n;
    lli a[n], b[n], c[n], dp[n][3];
    for(int i=0; i<n; i++)
        cin>>a[i]>>b[i]>>c[i];
    dp[0][0]=a[0], dp[0][1]=b[0], dp[0][2]=c[0];
    for(int i=1; i<n; i++)
        dp[i][0]=max(dp[i-1][1], dp[i-1][2])+a[i], dp[i][1]=max(dp[i-1][0], dp[i-1][2])+b[i], dp[i][2]=max(dp[i-1][0], dp[i-1][1])+c[i];
    cout<<(max(dp[n-1][0], max(dp[n-1][1], dp[n-1][2])));
    return 0;
}