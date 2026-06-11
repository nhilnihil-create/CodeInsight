#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007
#define deb(x) cerr << "\n" \
                    << #x << "=" << x << "\n";
#define deb2(x, y) cerr << "\n"                   \
                        << #x << "=" << x << "\n" \
                        << #y << "=" << y << "\n";
#define w(x)  \
    int x;    \
    cin >> x; \
    while (x--)

const int N = 1e5 + 2;
int a[N], n;
int dp[N][3];
int go(int ind, bool invert)
{
    if (ind == n - 1)
    {
        if (invert)
            return -a[n - 1];
        else
            return a[n - 1];
    }
    if (dp[ind][invert] != -1)
        return dp[ind][invert];

    //means i have inverted the prev element
    if (invert)
        return dp[ind][invert] = max(go(ind + 1, 0) - a[ind], go(ind + 1, 1) + a[ind]);

    return dp[ind][invert] = max(go(ind + 1, 0) + a[ind], go(ind + 1, 1) - a[ind]);
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    memset(dp, -1, sizeof dp);
    cout << go(0, 0);
    return 0;
}