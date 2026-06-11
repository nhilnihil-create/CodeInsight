#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

const ll inf = (1LL<<62);

int n;
ll arr[405];
ll dp[405][405];

ll recur(int i, int j)
{
    if(j == i) return 0;
    if(j == i+1) return arr[i]+arr[j];
    if(dp[i][j] != -1) return dp[i][j];

    ll cost = inf;
    for(int k=i; k<j; k++)
    {
        cost = min(cost,recur(i,k)+recur(k+1,j));
    }
    for(int k=i; k<=j; k++)
        cost += arr[k];
    return dp[i][j] = cost;
}

int main()
{
    FASTIO
    memset(dp,-1,sizeof(dp));
    cin >> n;
    for(int i=0; i<n; i++) cin >> arr[i];
    recur(0,n-1);
    ll ans = (n > 2) ? dp[0][n-1] : arr[0]+arr[1];
    cout << ans << "\n";
    return 0;
}