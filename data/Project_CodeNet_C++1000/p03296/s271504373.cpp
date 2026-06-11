#include <bits/stdc++.h>
#define pb push_back
#define pi pair<int, int>
#define l first
#define r second
#define all(x) x.begin(), x.end()
#define fori(a, b, step) for (int i = a; i < b; i += step)
#define forj(a, b, step) for (int j = a; j < b; j += step)

const int maxn = 5e5 + 1, CC = 10001;

using namespace std;

short a[100];
short dp[100][10001];
short sm[10001], pm[10001];

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    fori (0, n, 1)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < CC; j++)
            dp[i][j] = 1e9;
    for (int i = 0; i < CC; i++)
        dp[0][i] = 1;
    dp[0][a[0]] = 0;
    pm[0] = sm[CC - 1] = 1e9;
    for (int i = 1; i < CC; i++)
        pm[i] = min(pm[i - 1], dp[0][i]);
    for (int i = CC - 1; i > 0; i--)
        sm[i - 1] = min(sm[i], dp[0][i]);
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < CC; j++) {
            dp[i][j] = (j != a[i]) + min(pm[j - 1], sm[j]);
        }
        for (int j = 1; j < CC; j++)
            pm[j] = min(pm[j - 1], dp[i][j]);
        for (int j = CC - 1; j > 0; j--)
            sm[j - 1] = min(sm[j], dp[i][j]);
    }
    cout << sm[0];
    return 0;
}
