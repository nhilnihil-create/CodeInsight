#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 10, mod = 1e9 + 7;
long long a[maxn], dp[maxn], c[maxn], n;

int main()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    dp[0] = dp[1] = 1;
    c[a[1]] += dp[0];
    for(int i = 2; i <= n; i++){
        if(a[i] != a[i - 1])
            c[a[i]] += dp[i - 1];
        dp[i] = (c[a[i]] % mod);
    }
    cout << dp[n] % mod;
}