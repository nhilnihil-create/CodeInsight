#include <bits/stdc++.h>
/*#ifndef LOCAL_RUN
    #pragma GCC optimize("Ofast")
    #pragma GCC optimize("unroll-loops")
    #pragma GCC optimize("fast-math")
    #pragma GCC target("avx2,tune=native")
#endif*/
#define X first
#define Y second
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int N = 2e5 + 228;

ll dp[N][3], a[N][3];

int main()
{
    #ifdef LOCAL_RUN
        freopen("input.txt", "r", stdin);
    //#else
        //freopen("tickets.in", "r", stdin);
        //freopen("tickets.out", "w", stdout);
    #endif
	ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i][0] >> a[i][1] >> a[i][2];
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                if (j == k) continue;
                dp[i][j] = max(dp[i][j], dp[i-1][k] + a[i][j]);
            }
        }
    }
    cout << max(max(dp[n][0], dp[n][1]), dp[n][2]);

    return 0;
}

// 272472LF
