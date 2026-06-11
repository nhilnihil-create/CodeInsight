#include <iostream>

using namespace std;

const int mod = 1e9 + 7;
int n, c[200005], dp[200005], cnt[200005];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> c[i];
        if (c[i] == c[i - 1])
        {
            i--;
            n--;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        dp[i] = (dp[i - 1] + cnt[c[i]]) % mod;
        cnt[c[i]] = (cnt[c[i]] + dp[i - 1] + 1) % mod;
    }
    cout << (dp[n] + 1) % mod << endl;
    return 0;
}