#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb push_back
#define mp make_pair

typedef pair<int, int> ii;

const int mod = 1e9 + 7;

const int N = 3005;

int n, dp[N][N], pref[N][N];

string s;

int add(int x, int y) {
    return (1ll * x + 1ll * y) % mod;
}

int mul(int x, int y) {
    return (1ll * x * 1ll * y) % mod;
}

int del(int x, int y) {
    return ((1ll * x - 1ll * y) % mod + mod) % mod;
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    cin >> n;
    cin >> s;
    s = "++" + s;
    dp[1][1] = 1;
    pref[1][1] = 1;
    for(int j = 2; j <= n; j++)
        pref[1][j] = add(pref[1][j], pref[1][j - 1]);
    for(int i = 2; i <= n; i++) {
        for(int j = 1; j <= i; j++) {
            if(s[i] == '<')
                dp[i][j] = add(dp[i][j], pref[i - 1][j - 1]);
            else
                dp[i][j] = add(dp[i][j], del(pref[i - 1][n], pref[i - 1][j - 1]));
        }
        for(int j = 1; j <= n; j++) {
            pref[i][j] = dp[i][j];
            pref[i][j] = add(pref[i][j], pref[i][j - 1]);
        }
    }
    int sum = 0;
    for(int i = 1; i <= n; i++)
        sum = add(sum, dp[n][i]);
    cout << sum;
}
