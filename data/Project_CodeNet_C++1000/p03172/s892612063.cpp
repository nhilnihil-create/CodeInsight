#include<bits/stdc++.h>

using namespace std;

long long dp[101][100020];
vector<int> a(102);
vector<long long> pref(100050);
long long mod = 1e9 + 7;

int main()
{
    int N, K;

    cin >> N >> K;

    for(int i = 1; i <= N; i++)
        cin >> a[i];

    for(int i = 0; i <= K; i++)
        pref[i] = 0;

    for(int i = 0; i <= N; i++)
    {
        for(int j = 0; j <= K; j++)
        {
            dp[i][j] = 0;
        }
    }

    for(int j = 0; j <= a[N]; j++)
    {
        dp[N][j] = 1;
    }

    long long res = 0;



    for(int i = N-1; i >= 0; i--)
    {
        pref[0] = 1;

        for(int j = 1; j <= K; j++)
            pref[j] = (pref[j-1] + dp[i+1][j]) % mod;

        for(int j = 0; j <= K; j++)
        {
            if(j-1-a[i] < 0) dp[i][j] = pref[j];
            else dp[i][j] = (pref[j] - pref[j - 1 - a[i]] + mod) % mod;
        }
    }

    cout << dp[1][K] << endl;

    return 0;
}
