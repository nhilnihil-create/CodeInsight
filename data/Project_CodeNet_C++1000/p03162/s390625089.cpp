#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <iomanip>
#include <cstdio>
#include <set>
#include <map>
#include <list>
#include <cstdlib>
#include <queue>
#include <stack>
#include <bitset>

using namespace std;

#define MOD 1000000007
#define PI 3.1415926535897932
#define rep(i, n) for (int i = 0; i < n; i++)
#define repe(i, j, n) for (int i = j; i < n; i++)
#define repi(i, n) for (int i = 0; i <= n; i++)
#define repie(i, j, n) for (int i = j; i <= n; i++)
#define all(x) x.begin(), x.end()
#define println() cout << endl
#define P pair<int, int>
#define fi first
#define se second

typedef long long ll;

long long modinv(long long a, long long m)
{
    long long b = m, u = 1, v = 0;
    while (b)
    {
        long long t = a / b;
        a -= t * b;
        swap(a, b);
        u -= t * v;
        swap(u, v);
    }
    u %= m;
    if (u < 0)
        u += m;
    return u;
}

void solve1()
{
    int n; cin >> n;
    vector<int> a(n), b(n), c(n);
    rep(i, n) {
        cin >> a[i] >> b[i] >> c[i];
    }

    int dp[n+1][3]; 
    dp[0][0] = a[0];
    dp[0][1] = b[0];
    dp[0][2] = c[0];

    for(int i = 1; i < n+1; i++)
    {
        dp[i][0] = max(dp[i - 1][1] + a[i], dp[i - 1][2] + a[i]);
        dp[i][1] = max(dp[i - 1][0] + b[i], dp[i - 1][2] + b[i]);
        dp[i][2] = max(dp[i - 1][0] + c[i], dp[i - 1][1] + c[i]);
    }

    int ans = max({dp[n][0], dp[n][1], dp[n][2]});

    cout << ans << endl;
}

int main()
{
    solve1();
}
