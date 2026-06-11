#include <bits/stdc++.h>
using namespace std;
#define Hello ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define endl '\n'
void trace(int n, int arr[]){for(int i = 0; i < n; i++){cout << arr[i] << " ";} cout << endl << endl;}
const int N = 21, mod = 1e9 + 7;
ll n, dp[N + 2][(1 << 21) + 3], arr[N + 2][N + 2];
ll solve(int idx, int msk){
    if(idx >= n)
        return 1;
    if(dp[idx][msk] != -1)
        return dp[idx][msk];
    ll ans = 0;
    for(int i = 0; i < n; i++)
        if(arr[idx][i] && !((msk >> i) & 1))
            ans = (ans + (solve(idx + 1, (msk | (1 << i))) % mod)) % mod;
    dp[idx][msk] = ans;
    return ans;
}
int main()
{
    Hello
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> arr[i][j];
    memset(dp, -1, sizeof dp);
    cout << solve(0, 0);
    return 0;
}