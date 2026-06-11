#include <iostream>

using namespace std;

const int NMAX = 1000;
const int MOD = 1e9 + 7;

int N, M;
char s[NMAX + 2][NMAX + 2];

int dp[NMAX + 2][NMAX + 2];

int main()
{
    cin >> N >> M;

    for(int i = 1; i <= N; i++)
        cin >> (s[i] + 1);

    dp[1][1] = 1;

    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= M; j++)
            if(s[i][j] == '.' && !(i == 1 && j == 1))
                dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;

    cout << dp[N][M] << '\n';

    return 0;
}
