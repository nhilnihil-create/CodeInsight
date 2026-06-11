#include <bits/stdc++.h>
#define ull uint64_t
#define ll long long int
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define mx5 100005
#define mx6 1000005
#define mod 1000000007
#define nfs ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

ll dp[(1<<16) - 1] = {}, inp[16][16] = {};

int main() {
    nfs
    int i, j, n, mask;
    cin >> n;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            cin >> inp[i][j];
    
    for (mask = 1; mask < (1<<n); mask++) {
        int last = __builtin_ctz(mask);
        int rmask = mask & (mask-1);
        
        dp[mask] = dp[rmask];
        for (int tmp = rmask; tmp; tmp = tmp & (tmp-1))
            dp[mask] += inp[last][__builtin_ctz(tmp)];
    }

    for (mask = 1; mask < (1<<n); mask++)
        for (int submask = mask; submask; submask = mask & (submask-1))
            dp[mask] = max(dp[mask], dp[submask] + dp[mask^submask]);

    cout << dp[(1 << n) -1];    
}