#include <bits/stdc++.h>

#define ll long long
#define MAXN 110
#define MAXK 100010

using namespace std;

ll dp[MAXN][MAXK];
const ll mod = 1e9 + 7;

ll add(ll a, ll b) {

    a += b;
    if(a >= mod)
        a -= mod;
    return a;
}

ll sub(ll a, ll b) {

    a += mod - b;
    a %= mod;
    return a;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;

    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    
    for(int i = 0; i <= n; i++)
        dp[i][0] = 1;
    ll pre[k + 1];
    for(int i = 0; i <= k; i++)
        pre[i] = i ? pre[i - 1] : 0 + dp[0][i];
    for(int i = 1; i <= n; i++) {
        ll temp[k + 1];
        temp[0] = dp[i][0];
        for(int j = 1; j <= k; j++) {
            int mn = j - min(arr[i - 1], j);
            dp[i][j] = pre[j];
            if(mn)
                dp[i][j] = sub(dp[i][j], pre[mn - 1]);
            /*
            for(int o = min(arr[i - 1], j); o >= 0; o--)
                dp[i][j] = add(dp[i][j], dp[i - 1][j - o]);
            */
            temp[j] = add(temp[j - 1], dp[i][j]);
        }

        for(int j = 0; j <= k; j++)
            pre[j] = temp[j];
    }
    cout << dp[n][k] << endl;
    return 0;
}
