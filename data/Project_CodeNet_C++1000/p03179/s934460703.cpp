#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
int N;
string s;
const ll MOD = 1e9 + 7;
ll dp[3010][3010];
ll psum[3010];

int main()
{
    cin >> N >> s;
    memset(dp, 0, sizeof(dp));
    for(int i = 0; i < N; i++) dp[0][i] = 1;
    memset(psum, 0, sizeof(psum));
    psum[0] = 0;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N - i; j++) 
        {
            psum[j + 1] = psum[j] + dp[i][j];
            psum[j + 1] %= MOD;
        }
        for(int j = 0; j < N - i; j++)
        {
            if(s[i] == '>')
            {
                dp[i + 1][j] = psum[N - i] - psum[j + 1];
                if(dp[i + 1][j] < 0) dp[i + 1][j] += MOD;
            }
            else dp[i + 1][j] = psum[j + 1];
            dp[i + 1][j] %= MOD;
        }
        memset(psum, 0, sizeof(psum));
    }
    ll res = 0;
    for(int i = 0; i < N; i++)
    {
        res += dp[N][i] % MOD;
        res %= MOD;
    }

    cout << res << endl;
    
}
