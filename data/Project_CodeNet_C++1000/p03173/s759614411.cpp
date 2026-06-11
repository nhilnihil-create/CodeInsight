#include <bits/stdc++.h>

#define ll long long
#define MAXN 410

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    ll arr[n], pre[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];

        pre[i] = (i ? pre[i - 1] : 0) + arr[i];
    }
    
    ll dp[n][n];
    for(int len = 0; len < n; len++) {
        for(int l = 0; l < n - len; l++) {
            int r = l + len;
            if(len == 0) {
                dp[l][r] = 0;
                continue;
            }

            dp[l][r] = LLONG_MAX;
            for(int k = l; k < r; k++)
                dp[l][r] = min(dp[l][r], dp[l][k] + dp[k + 1][r] + pre[r] - (l ? pre[l - 1] : 0));
        }
    }
    
    cout << dp[0][n - 1] << endl;
    return 0;
}
