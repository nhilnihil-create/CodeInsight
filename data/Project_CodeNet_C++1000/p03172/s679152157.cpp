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

ll dp[101][mx5] = {};

int main() {
    nfs
    int i, j, n, k, a[101] = {};
    
    cin >> n >> k;
    
    for (i = 1; i <= n; i++)
        cin >> a[i];

    for (i = 1, j = 0; j <= k; j++) {
        dp[i][j] = min(j + 1, a[i] + 1);
    }

    for (i = 2; i <= n; i++) {
        ll temp_sum = 0;
        for (j = 0; j <= k; j++) {
            temp_sum = (temp_sum + dp[i-1][j]) % mod;
            temp_sum = (temp_sum + ( mod - ((a[i] + 1 <= j) ? dp[i - 1][j - (a[i]+1)] : 0) ) % mod ) % mod;
            dp[i][j] = temp_sum;
        }
    }
    cout << (dp[n][k] + (mod - dp[n][k-1]) % mod) % mod;
}