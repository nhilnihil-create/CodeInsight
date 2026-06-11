#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int MOD = 1e9 + 7;
void add(int &a, int b)
{
    a = (a + b) % MOD;
}
int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    vector<vector<int>> dp(n+1, vector<int>(k+1, 0));
    dp[0][0] = 1;
    for(int i = 1; i <= n; i++)
    {
        int num = 0;
        for(int j = 0; j <= k; j++)
        {
            add(num, dp[i-1][j]);
            dp[i][j] = num;
            if(j-a[i-1] >= 0) add(num, -dp[i-1][j-a[i-1]]);
        }
    }
    cout << (dp[n][k]+MOD)%MOD << endl;
}
