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

ll dp[401][401] = {}, part[401] = {};

int main() {
    nfs
    int i, j, k, n, a, d;
    cin >> n;
    for (i = 1; i <= n; i++) {
        cin >> a;
        part[i] = part[i-1] + a;
        dp[i][i] = 0;
    }

    for (d = 1; d < n ; d++) {
        for (i = 1, j = i + d; j <= n; i++, j++) {
            dp[i][j] = 1e18;
            for (k = i; k < j; k++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j]);
            }
            dp[i][j] += part[j] - part[i-1];
        }
    }
    cout << dp[1][n];
}