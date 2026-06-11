#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>

#define MAXN 105
#define MAXK 100005

using namespace std;

typedef long long ll;

int mod = 1e9 + 7;
int dp[MAXN][MAXK];
int prefix[MAXK], candies[MAXN];

int range(int i, int j) {
    if(i == 0) return prefix[j];
    return (prefix[j] - prefix[i - 1] + mod) % mod;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> candies[i];
    }
    dp[0][0] = 1;
    for(int i = 1; i <= k; i++) {
        dp[0][i] = 0;
    }
    for(int i = 1; i <= n; i++) {
        prefix[0] = dp[i - 1][0];
        for(int j = 1; j <= k; j++) {
            prefix[j] = (prefix[j - 1] + dp[i - 1][j]) % mod;
        }
        for(int j = 0; j <= k; j++) {
            dp[i][j] = range(max(j - candies[i - 1], 0), j);
        }
    }
    cout << dp[n][k] << '\n';

    return 0;
}