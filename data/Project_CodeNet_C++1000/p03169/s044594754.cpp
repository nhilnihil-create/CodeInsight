//Created by: Aditya Singh
//Bleed Blue
#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define unm unordered_map<int,int>
#define pb emplace_back
#define nt _int128
#define PI 3.1415926535897932384626433
#define inf 1e18

const int N = 305;

ld dp[N][N][N];

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    // int t;cin>>t;while(t--)
    {
        int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
        cin >> n;
        int ar[4] = {0};
        for (i = 0; i < n; i++)
            cin >> m, ar[m]++;
        int mx_1 = ar[1] + ar[2] + ar[3], mx_2 = ar[2] + ar[3], mx_3 = ar[3];
        for (k = 0; k <= mx_3; k++)
        {
            for (j = 0; j <= mx_2 - k; j++)
            {
                for (i = 0; i <= mx_1 - j - k; i++)
                {
                    if (i + j + k == 0)
                        continue;
                    dp[i][j][k] = (ld)n / (i + j + k);
                    if (i > 0)
                        dp[i][j][k] += dp[i - 1][j][k] * i / (ld)(i + j + k);
                    if (j > 0)
                        dp[i][j][k] += dp[i + 1][j - 1][k] * j / (ld)(i + j + k);
                    if (k > 0)
                        dp[i][j][k] += dp[i][j + 1][k - 1] * k / (ld)(i + j + k);
                }
            }
        }
        cout << fixed << setprecision(10) << dp[i - 1][j - 1][k - 1];
    }
    return 0;
}