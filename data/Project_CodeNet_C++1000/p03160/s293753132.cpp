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

ll dp[N], arr[N];

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
        cin >> arr[i];
    arr[0] = arr[1];
    for (int i = 2; i <= n; i++) {
        dp[i] = min(dp[i-1] + abs(arr[i-1] - arr[i]), dp[i-2] + abs(arr[i-2] - arr[i]));
        dp[i-1] = min(dp[i-1], dp[i] + abs(arr[i] - arr[i-1]));
    }
    cout << dp[n];

    return 0;
}

// 272472LF
