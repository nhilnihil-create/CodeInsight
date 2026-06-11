#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 3005
#define M 1000000007

ll dp[N][N], sum[N];

int main()
{
    int n;
    string s;
    cin >> n >> s;
    dp[1][1] = 1;
    for(int i = 2; i <= n; i++)
    {
        for(int j = 1; j <= n; j++) sum[j] = (sum[j - 1] + dp[i - 1][j]) % M;
        for(int j = 1; j <= i; j++)
        {
            if(s[i - 2] == '<') dp[i][j] = sum[j - 1];
            else dp[i][j] = (sum[n] - sum[j - 1] + M) % M;
        }
    }
    ll ans = 0LL;
    for(int i = 1; i <= n; i++) ans = (ans + dp[n][i]) % M;
    cout << ans << endl;
}
