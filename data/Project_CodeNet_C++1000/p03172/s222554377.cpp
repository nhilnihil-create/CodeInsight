#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long

const ll mod = 1000000007;

ll prefix[105][100005];
ll dp[105][100005];
int arr[100005];

int main()
{
    FASTIO
    memset(dp,0,sizeof(dp));
    int n, k;
    cin >> n >> k;
    for(int i=0; i<n; i++) cin >> arr[i];
    for(int i=0; i<=k; i++) prefix[0][i] = 1;
    dp[0][0] = 1;
    for(int i=1; i<=n; i++)
    {
        for(int j=0; j<=k; j++)
        {
            int p = j-min(j,arr[i-1]);
            if(p == 0) dp[i][j] = prefix[i-1][j]%mod;
            else dp[i][j] = (prefix[i-1][j]%mod-prefix[i-1][p-1]%mod + mod)%mod;
            prefix[i][j] = (prefix[i][j-1]%mod+dp[i][j]%mod)%mod;
        }
    }
    cout << dp[n][k]%mod << "\n";
    return 0;
}