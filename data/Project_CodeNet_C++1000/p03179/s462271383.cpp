#include <bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define ld long double
#define pll pair<ll, ll>
#define pii pair<int, int>
#define f first
#define se second
#define pb push_back
#define ft fflush(stdout)
 
 
using namespace std;
 
 
const int N = 3e3 + 123;
const int PLS = 3e5 + 123;
const ll mod = 1e9 + 7;
const ll inf = 1e16;


ll n, dp[N], p[N], sf[N];
char s[N];


int main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> s[i];
    dp[1] = 1;
    p[0] = sf[n + 1] = 0;
    for (int j = 1; j <= n; j++)
        p[j] = (p[j - 1] + dp[j]) % mod;
    for (int j = n; j >= 1; j--)
        sf[j] = (sf[j + 1] + dp[j]) % mod;
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            dp[j] = 0;
        for (int j = 1; j <= i; j++) {
            if (s[i - 1] == '<')
                dp[j] = p[j - 1];
            else
                dp[j] = sf[j];
        }
        for (int j = 1; j <= n; j++)
            p[j] = (p[j - 1] + dp[j]) % mod;
        for (int j = n; j >= 1; j--)
            sf[j] = (sf[j + 1] + dp[j]) % mod;
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++)
        ans = (ans + dp[i]) % mod;
    cout << ans;
}
