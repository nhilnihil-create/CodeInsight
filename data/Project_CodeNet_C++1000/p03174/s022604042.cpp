#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

const ll mod = 1e+9 + 7;

int n, x;
bool arr[25][25];
ll dp[25][1<<22];

ll recur(int i, int j)
{
    if(i == n && j == ((1<<n)-1)) return 1;
    if(i == n) return 0;
    if(dp[i][j] != -1) return dp[i][j];

    ll ways = 0;
    for(int b=0; b<n; b++)
    {
        if(!(j&(1<<b)))
        {
            if(arr[i][b])
                ways = (ways%mod+recur(i+1,j|(1<<b)%mod))%mod;
        }
    }
    return dp[i][j] = ways;
}

int main()
{
    FASTIO
    memset(dp,-1,sizeof(dp));
    cin >> n;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
            cin >> arr[i][j];
    }
    recur(0,0);
    cout << dp[0][0]%mod << "\n";
    return 0;
}