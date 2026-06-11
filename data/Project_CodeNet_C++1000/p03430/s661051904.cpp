#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int Nmax = 303;

int ans, i, j, k, K, N, dp[Nmax][Nmax][Nmax];
char a[Nmax];

int main()
{
  //  freopen("input", "r", stdin);
  //  freopen("output", "w", stdout);
    cin.sync_with_stdio(false);

    cin >> (a+1) >> K;
    N = strlen(a+1);

    for(i=N; i; --i)
        for(j=i; j<=N; ++j)
            for(k=0; k<=K; ++k)
            {
                if(i == j) dp[i][j][k] = 1;
                    else if(a[i] == a[j]) dp[i][j][k] = 2 + dp[i+1][j-1][k];
                        else
                        {
                            dp[i][j][k] = max(dp[i+1][j][k], dp[i][j-1][k]);
                            if(k) dp[i][j][k] = max(dp[i][j][k], dp[i+1][j-1][k-1] + 2);
                        }
            }

    for(i=0; i<=K; ++i) ans = max(ans, dp[1][N][i]);
    cout << ans << '\n';
    return 0;
}
